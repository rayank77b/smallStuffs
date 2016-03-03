# Information about Git 

* http://www.vogella.com/tutorials/Git/article.html
* https://www.atlassian.com/git/tutorials/
* http://git-scm.com/docs/gittutorial

eigene Repo erstellen:
```bash
git init
```

repo auschecken/klonen
```bash
git clone /pfad/zum/repository
git clone benutzername@host:/pfad/zum/repository
git clone http://bluber@someDomain.com:8080/gitblit/git/Bla.git 
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


git checkout         # Checkout a branch or paths to the working tree

git status

git add path/file   # add a file to git


git config --global user.name "Blub Bluber"
git config --global user.email blub@blub.de
git commit --amend --reset-author









