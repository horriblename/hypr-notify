{
  # WARNING this is mainly for testing if it will work in nix
  # depending on which part of hyprland is used, it may be necessary to add
  # the dependencies of Hyprland here as well
  description = "Hyprland notification plugin";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    hyprland.url = "github:hyprwm/Hyprland";
  };

  outputs = { self, nixpkgs, hyprland }:
    let
      pkgs = nixpkgs.legacyPackages.x86_64-linux;
      hyprland-headers = hyprland.outPath;
    in
    {
      packages.x86_64-linux.hypr-notify = pkgs.stdenv.mkDerivation {
        HYPRLAND_HEADERS = hyprland-headers;
        name = "hypr-notify";
        src = ./.;
        buildPhase = "make all";
        installPhase = ''
          mkdir -p $out/usr/lib/hyprland-plugins
          cp hypr-notify.so $out/usr/lib/hyprland-plugins
        '';
      };

      packages.x86_64-linux.default = self.packages.x86_64-linux.hypr-notify;

    };
}
