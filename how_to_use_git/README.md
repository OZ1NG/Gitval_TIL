# git 사용법

## 시작
### 로컬 저장소 만들기
1. git bash에서 자신이 원하는 디렉토리로 이동하기
2. git clone [github 주소 입력] <br/> ex) TIL 레포를 추가하고 싶은 경우 : git clone https://github.com/gitval-github/TIL
#### Reference0
https://gmlwjd9405.github.io/2017/10/27/how-to-collaborate-on-GitHub-1.html

### branch 생성/삭제/이동
1. branch 생성
```
git branch [branch 이름]
```
2. branch 삭제
```
git branch -d [branch 이름]
```
3. 생성한 branch로 이동
```
git checkout [branch 이름] 
```
3-1. 생성한 branch 원격 Repo에 push 
```
git push --set-upstream origin [branch 이름]
```
#### Reference1
https://goddaehee.tistory.com/274

## 파일 업로드/관리
### 파일 업로드
1. **status** : 디렉토리에 추가/변경된 파일들을 확인할 수 있다. <br/> 빨간색이면 관리 대상이 아닌 것이다.
```
git status
```
2. **add** : 파일을 git 관리대상으로 변경한다.
```
git add [파일 이름]
```
여기서 해당 디렉토리 내의 모든 비관리 대상 파일들을 관리 대상으로 변경하고 싶으면 아래와 같이 하면 된다.
```
git add .
```
3. **restored** : git 관리대상인 파일을 다시 비관리 대상으로 변경한다.
```
git restored --staged [파일 이름]
```
4. **commit** : 수정된 내용을 git에 저장한다.
```
git commit -m "설명"
```
이때, add와 commit을 한번에 하려면 -am옵션을 주면 된다.
```
git commit -am "설명"
```
5. **push** : commit 완료된 파일들을 원격 Repo에 추가한다.
```
git push
```
#### Reference2
https://www.zerocho.com/category/Git/post/580f633046f4fe09815b72a5

### 파일 관리
1. **mv** : 파일 이동 : 리눅스의 mv와 똑같다.
```
git mv [src 파일 경로] [dest 파일 경로]
```
2. **rm** : 파일 삭제 : 리눅스의 rm과 똑같다.
```
git rm [파일 경로]
```
3. **log** : 커밋된 내역을 볼 수 있다.
```
git log
```

#### Reference3
https://www.zerocho.com/category/Git/post/580f633046f4fe09815b72a5

## 꾸미기
마크다운을 이용하여 꾸밀 수 있다.
<br/>명령어 참고 : https://gist.github.com/ihoneymon/652be052a0727ad59601

#### typora 편집기

성운이 형이 알려주신 마크다운 편집기이다. 결과를 바로 바로 확인할 수 있어서 좋다. ㅎ

**홈페이지 : https://typora.io/ **

**(ctrl + /)** : 서식을 수정해야 할 경우 사용

#### 끗

