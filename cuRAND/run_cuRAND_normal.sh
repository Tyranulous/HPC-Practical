#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=00:05:00
#SBATCH --job-name=cuRAND_normal
#SBATCH --gres=gpu:1

module purge
module load gpu/cuda

./cuRAND_normal
