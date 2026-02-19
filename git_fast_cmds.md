# Git fast cmds
## ✅ 1. Clone the repository
```
git clone https://github.com/username/repo.git
```
## (Optional: clone and immediately switch to a branch)
```
git clone -b branchname https://github.com/username/repo.git
```

## ✅ 3. List available branches
```
git branch -a
```

## ✅ 4. Checkout the branch you want
```
git checkout branchname
```

## If the branch only exists on the remote
```
git checkout -b branchname origin/branchname
```

## ✅ 5. Pull the latest updates from that branch
```
git pull
```
OR
```
git pull origin branchname
```

## Quick Summary
```
git clone https://github.com/username/repo.git
cd repo
git checkout branchname
git pull
```

## Others
```
git config --global user.name "XXX"
git config --global user.email "XXX"
git config --global --list

ls ~/.ssh
cd ~/.ssh
ssh-keygen -t ed25519 -C "EMAIL"
cat ~/.ssh/id_ed25519.pub

Go to:
GitHub → Settings → SSH and GPG keys → New SSH Key → Paste it.

git remote set-url origin git@github.com:USERNAME/REPOSITORY.git

git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/USERNAME/REPOSITORY.git
git push -f origin main
```
