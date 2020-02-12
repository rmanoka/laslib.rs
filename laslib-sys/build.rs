#[allow(dead_code)]
#[cfg(feature = "bindgen")]
fn write_bindings() {
    use std::env;
    use std::path::PathBuf;
    // Tell cargo to invalidate the built crate whenever the wrapper changes
    println!("cargo:rerun-if-changed=src/wrapper.hpp");

    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
    // The input header we would like to generate
    // bindings for.
        .header("src/wrapper.hpp")
    // Tell cargo to invalidate the built crate whenever any of the
    // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
    // Finish the builder and generate the bindings.
        .enable_cxx_namespaces()
        .clang_args(&["-x", "c++"])

        .whitelist_type("LAS.*")
        .whitelist_type("U64.*")
        .opaque_type("[^L][^A].*")
        .opaque_type("LASreaderLASrescalereoffset")
        .derive_debug(false)

        .generate()
    // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}

#[allow(unused_imports)]
use std::path::Path;
#[cfg(feature = "bindgen")]
fn write_hacks(dst: &Path) {
    use std::env;
    use std::path::PathBuf;

    let header = dst.join("include").join("cwrapper.h");
    let bindings = bindgen::Builder::default()
        .header(header.to_str().unwrap())
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .enable_cxx_namespaces()
        .clang_args(&["-x", "c++"])
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings-hacks.rs"))
        .expect("Couldn't write bindings!");

}

fn main() {
    // Tell cargo to tell rustc to link the system bzip2
    // shared library.
    let dst = cmake::build("hacks");

    println!("cargo:rustc-link-search=native={}", dst.join("lib").display());
    println!("cargo:rustc-link-lib=laslib-hacks");
    println!("cargo:rustc-link-lib=las");
    println!("cargo:rustc-link-lib=stdc++");
    #[cfg(feature = "bindgen")]
    write_bindings();
    #[cfg(feature = "bindgen")]
    write_hacks(&dst);
}
