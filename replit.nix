{ pkgs }: {
    deps = [
        pkgs.ls -al
        pkgs.cowsay
    ];
}