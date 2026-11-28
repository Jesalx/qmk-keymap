{
  description = "Dev shell for the QMK keymap (ZSA Voyager)";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  # Not used by the dev shell: it only records the qmk_firmware commit that CI
  # builds against, so `nix flake update` bumps it with the other pins.
  inputs.qmk_firmware = {
    url = "github:qmk/qmk_firmware";
    flake = false;
  };

  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forAllSystems = nixpkgs.lib.genAttrs systems;
    in
    {
      devShells = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.mkShell {
            packages = with pkgs; [
              actionlint
              clang-tools
              dfu-util
              go-task
              keymap-drawer
              qmk
            ];
          };
        }
      );
    };
}
