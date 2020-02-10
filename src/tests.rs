use super::*;

#[test]
#[ignore]
fn iterate_las() {
    use std::path::PathBuf;
    use std::time::Instant;
    let path: PathBuf = std::env::var_os("LASFILE")
        .expect("env LASFILE not set").into();

    let start = Instant::now();

    let mut reader = Reader::open(&path)
        .expect("open las failed");
    let num = reader.len();

    eprintln!("Loaded {} with {} points", path.display(), num);

    let idx = 9_000_000.min(num);
    assert!(reader.seek(idx));
    eprintln!("Seeked to idx {}", idx);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    let count = reader.points_iter(&mut |_| ()).count()
        as u64;
    eprintln!("Read {} points", count);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    assert_eq!(count, num - idx);
}

#[test]
#[ignore]
#[cfg(feature = "rayon")]
fn par_iterate_las() {
    use std::path::PathBuf;
    use std::time::Instant;
    let path: PathBuf = std::env::var_os("LASFILE")
        .expect("env LASFILE not set").into();

    let start = Instant::now();

    let reader = Reader::open(&path)
        .expect("open las failed");
    let num = reader.len();

    let idx = std::env::var_os("PT_START")
        .and_then(|s| s.to_str().and_then(|s| s.parse().ok()))
        .unwrap_or(0);

    let par_iter = par_points_iter(&path, &|_| (), idx, Some(num))
        .expect("creating par. iter");
    eprintln!("Created par. iter {} -> end", idx);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    use ::rayon::prelude::ParallelIterator;
    let count = ParallelIterator::count(par_iter) as u64;
    eprintln!("Read {} points", count);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    assert_eq!(count, num - idx);
}

#[test]
#[ignore]
#[cfg(feature = "rayon")]
fn thread_iterate_las() {
    use std::path::PathBuf;
    use std::time::Instant;
    let path: PathBuf = std::env::var_os("LASFILE")
        .expect("env LASFILE not set").into();

    let start = Instant::now();

    let reader = Reader::open(&path)
        .expect("open las failed");
    let num = reader.len();

    let par_iter = par_points_iter(&path, &|_| (), 0, None)
        .expect("create par iter");

    let mut num_threads = std::env::var_os("NUM_THREADS")
        .and_then(|s| s.to_str().and_then(|s| s.parse().ok()))
        .unwrap_or(8);

    let mut iters = Vec::with_capacity(2 * num_threads);
    iters.push(par_iter);
    while num_threads > 0 {
        for i in 0..iters.len() {
            if let Some(other) = iters[i].bisect() {
                iters.push(other);
            }
        }
        num_threads /= 2;
    }

    eprintln!("Created par. iters for {} threads", iters.len());
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    use ::rayon::prelude::*;
    let count = iters.into_par_iter()
        .map(|it| it.into_iter().count())
        .sum::<usize>() as u64;

    eprintln!("Read {} points", count);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    assert_eq!(count, num);
}

#[test]
#[ignore]
#[cfg(feature = "rayon")]
fn par_collect_into_vec_las() {
    use std::path::PathBuf;
    use std::time::Instant;
    let path: PathBuf = std::env::var_os("LASFILE")
        .expect("env LASFILE not set").into();

    let start = Instant::now();

    let reader = Reader::open(&path)
        .expect("open las failed");
    let num = reader.len();

    let par_iter = par_points_iter(&path, &|p| p.get_x(), 0, None)
        .expect("create par iter");

    use ::rayon::prelude::*;
    let mut out = Vec::with_capacity(num as usize);
    par_iter.collect_into_vec(&mut out);
    let count = out.len() as u64;

    eprintln!("Read {} points", count);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    assert_eq!(count, num);
}
