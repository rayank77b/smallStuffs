# Information about Git 

* http://www.vogella.com/tutorials/Git/article.html
* https://www.atlassian.com/git/tutorials/
* http://git-scm.com/docs/gittutorial
* http://git-scm.com/book/en/v2

get help
```
$ man git-log
$ git help log
```

eigene Repo erstellen:
```bash
git init
```

repo auschecken/klonen
```bash
git clone /pfad/zum/repository
git clone benutzername@host:/pfad/zum/repository
git clone http://bluber@someDomain.com:8080/gitblit/git/Bla.git 

git checkout         # Checkout a branch or paths to the working tree
```

working dir -> add -> index(stage) -> commit -> HEAD

adden 
```bash
git add <dateiname>
git add *
git add .
```

commiten
```bash
git commit -a -m "Commit-Nachricht"
git commit -m "Commit-Nachricht"
```

upload changes
```bash
git push origin master
git push
```

add a local repo to remote
```
git remote add origin <server>
```

branches: standrad branch is master

new branch
```
git checkout -b feature_x

git branch -d feature_x   # delete branch

git push origin <branch>  # upload branch
```

back to master
```
git checkout master

git checkout a1e8fb5
git checkout a1e8fb5 hello.py
git checkout HEAD hello.py

git revert <commit>

```

get new stuff
```
git pull
```

merge
```
git merge <branch>
```

differences between branches
```
git diff <quell_branch> <ziel_branch>
git diff --cached
```

infos
``` 
git status
git log
git log -p
git log --stat --summary
```

global config
```
git config --global user.name "Blub Bluber"
git config --global user.email blub@blub.de
git commit --amend --reset-author
git config color.ui true
git config format.pretty oneline
```

tagging
```
git tag 1.0.0 1b2e1d63ff
git log
```

back in history
```
git checkout -- <filename>
git fetch origin
git reset --hard origin/master
```
Add a remote git repo

REPO=snakeGame.git
git remote add -f ${REPO} git@github.com:rayank77b/${REPO}
git merge ${REPO}/main --allow-unrelated-histories



























