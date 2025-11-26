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
