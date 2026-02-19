# HG_Upload_Models
du -sh FOLDER
zip -r archive.zip foldername
zip -e archive.zip file.txt

sudo apt update
sudo apt install zip

sudo apt update
sudo apt install git git-lfs
git lfs install

pip install huggingface_hub
huggingface-cli login

# Upload ZIP to Model
hf upload reply-area42/G1_2026-02-16-11-50-17-diffusion yourfile.zip

hf auth whoami
hf auth logout
