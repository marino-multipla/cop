# SETUP unitree_IL_lerobot_gr00t.md

This installs: gcc, g++,make,libc, headers
```
sudo apt update
sudo apt install build-essential
```

Setup 
```
git clone --recurse-submodules https://github.com/unitreerobotics/unitree_IL_lerobot.git
git submodule update --init --recursive
conda create -y -n unitree_lerobot python=3.10
conda activate unitree_lerobot
conda install pinocchio -c conda-forge
conda install ffmpeg=7.1.1 -c conda-forge

pip install "torch>=2.2.1,<2.8.0" "torchvision>=0.21.0,<0.23.0" # --index-url https://download.pytorch.org/whl/cu1XX
pip install ninja "packaging>=24.2,<26.0" # flash attention dependencies

sudo apt install nvidia-cuda-toolkit
pip install psutil

pip install "flash-attn>=2.5.9,<3.0.0" --no-build-isolation
python -c "import flash_attn; print(f'Flash Attention {flash_attn.__version__} imported successfully')"

pip install lerobot[groot]

cd unitree_IL_lerobot && pip install -e .
```
