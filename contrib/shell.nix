with import <nixpkgs> {};
clangStdenv.mkDerivation {
  name = "clang-nix-shell";
  buildInputs = [ llvmPackages_13.openmp meson ninja ];
}
