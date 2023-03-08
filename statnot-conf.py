#!/bin/statnot

import subprocess


def update_text(text):
    if text == "":
        return
    subprocess.run(["hyprctl", "dispatch", "notify", text])
