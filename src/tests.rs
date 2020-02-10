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
    reader.seek(idx);
    eprintln!("Seeked to idx {}", idx);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    let count = reader.points_iter(&mut |_| ()).count()
        as u64;
    eprintln!("Read {} points", count);
    eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

    assert_eq!(count, num - idx);
}
