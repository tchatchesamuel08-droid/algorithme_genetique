import os
import subprocess

# Nom de l'exécutable
EXE_NAME = "GAVisualizer.exe"

# Dossiers
SRC_DIR = "src"
IMGUI_DIR = "thirdparty/imgui-master"

# Fichiers source du projet
sources = [
    os.path.join(SRC_DIR, f) for f in os.listdir(SRC_DIR) if f.endswith(".cpp")
]
# Fichiers ImGui
imgui_sources = [
    f"{IMGUI_DIR}/imgui.cpp",
    f"{IMGUI_DIR}/imgui_draw.cpp",
    f"{IMGUI_DIR}/imgui_widgets.cpp",
    f"{IMGUI_DIR}/imgui_tables.cpp",
    f"{IMGUI_DIR}/backends/imgui_impl_sdl3.cpp",
    f"{IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp",
]

# Commande de compilation
command = [
    "g++",
    "-std=c++20",
    "-O2",
    *sources,
    *imgui_sources,
    "-I", IMGUI_DIR,
    "-I", f"{IMGUI_DIR}/backends",
    "-lSDL3",
    "-o", EXE_NAME
]

print("Compilation en cours...")
subprocess.run(command, check=True)
print("Compilation terminée :", EXE_NAME)
