# Git 기초

## 1. Git 초기 설정
```
git config --global user.email "tetepiti149@naver.com"
git config --global user.name "tetepiti149"

git config --global -l
git config --global --list
```

## 2. Git 기본 용어
`working Directory` : 사용자가 작업하고 있는 공간
`Staging Area` : 커밋을 위한 파일/폴더가 추가되는 공간
git add README.md
git add README.asset
`Repositary` : 커밋 내용이 저장되는 공간

## 3. Git 명령어
### `git init`: `.git`폴더 생성 => git을 사용한다!
- 1번만!
- 하위 폴더에는 진행 X

### `git status` : git으로 관리되고 있는 상태를 확인하는 명령어

=> 파일 생성, 수정, 삭제 => 변경 사항 발생!!!

### `git add` : 변경사항이 발생한 파일을 `staging area`에 올리는 명령어
- 파일이름
  - 경로
    - 절대경로 : 풀네임 ex ) 
    - 상대경로 : `.`현재 경로 `..` 상대경로
`modified` : 기존 파일과 비교해서 변경 사항이 발생한 파일
`untracked` : 기존 폴더 구조에서 없던 친구

### `git commit` : 커밋을 작성하는 명령어 (staging에 있던 파일를 기록으로 남기는 명령어)

### `git log` : 지금까지 작성한 commit에 기록들을 확인하는 명령어
- 내용이 많아질 경우에는 특별한 뷰 모드가 활성화 => 빠져나오려면 q