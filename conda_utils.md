# conda utils

## ✅ Method 1 (Recommended): Clone the environment directly
conda create --name new_env_name --clone old_env_name
conda activate lerobot_gpu

## ✅ Method 2: Export + Recreate (More Portable)
conda activate old_env_name
conda env export > env.yaml
conda env create -f env.yaml

## ✅ Method 3: Exact explicit spec (most reproducible)
conda list --explicit > spec.txt
conda create --name new_env_name --file spec.txt

## Situation	Best Method
Same machine	--clone
Different machine	env export
Need exact binary builds	--explicit
