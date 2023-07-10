# DarkWeb-Parser 만들기

## 필요한 것들

- 환경 : Ubuntu-20.04 (WLS2)

- tor 데몬
  - ```bash
    # tor 데몬 설치
    sudo apt-get install tor
    
    # tor 데몬 실행
    sudo service tor start 
    # 데몬을 실행하면 127.0.0.1:9050 으로 새로운 포트가 열린다. (이 포트로 tor로 통신 할 수 있다.)
    
    # tor 데몬 종료
    sudo service tor stop
    ```

- python3 socks 모듈

  - ```bash
    python3 -m install Pysocks
    ```

- python3 beautifulsoup4 모듈

  - ```bash
    python3 -m pip install beautifulsoup4
    ```
  
- 포트 열린거 확인하는 명령어

  - ```bash
    # 설치
    sudo apt install net-tools
    # 명령어
    netstat -lnp | grep "LISTEN"
    # 또는
    netstat -antp
    ```




## Tor 파서 만들기!

- Tips
  - http://httpbin.org : 파서 만들때 도움 많이 된다.
    - api로 기능들을 구현해줌.
    - 예 : http://httpbin.org/ip : 내 ip를 알려줌

- 내가 만든 tor 파서 소스코드

  ```python
  # python3
  # make by OZ1NG
  import requests
  import sys
  from bs4 import BeautifulSoup
  import argparse
  import subprocess
  
  def get_session(): # 토르를 사용중이면 세션으로 프록시 설정
      session = requests.session()
      if(check_tor_service()):
          session.proxies = {'http':  'socks5h://127.0.0.1:9050', 'https': 'socks5h://127.0.0.1:9050'} # socks5h를 꼭 붙여줘야함.
      return session
  
  def usage():
      print("[!] Usage : python3 ./parser.py --help or -h")
      exit(0)
  
  def check_my_ip():
      global seesion
      if (check_tor_service()):
          msg = "Tor IP: "
      else:
          msg = "Public IP: "
      print(msg + session.get("http://httpbin.org/ip").text)
      
  def check_tor_service():
      command = []
      command.append('service')
      command.append('tor')
      command.append('status')
      fd_popen = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
      check_result, _ = fd_popen.communicate()
      if (b"tor is not running" in check_result):
          print("[-] tor is not running!")
          return False
      elif (b"tor is running" in check_result):
          print("[+] tor is running!")
          return True
      
  
  arg = argparse.ArgumentParser(description='my tor parser')
  # argument는 원하는 만큼 추가한다.
  arg.add_argument('--url', '-u', default=None, help='--url/-u [Parse Target URL]')
  arg.add_argument('--tag', '-t', default=None, help='--tag/-t [Parse Tag name]')
  arg.add_argument('--tor_check', '-T' ,action='store_const', const=True, help='--tor_check')
  arg.add_argument('--ip', '-i', action='store_const', const=True,  help='--ip')
  
  args = arg.parse_args()
  
  if(len(sys.argv) < 2):
      arg.print_help()
      exit()
  
  site_addr = args.url
  tag = args.tag
  tag_flag = 0
  tor_check_flag = args.tor_check
  ip_check_flag = args.ip
  
  session = get_session()
  
  if ((site_addr == None) and (ip_check_flag == None)):
      if(tor_check_flag != True):
          usage()
  if (tag != None):
      tag_flag = 1
  if (tor_check_flag != None):
      pass
  if (ip_check_flag != None):
      check_my_ip()
  
  if(site_addr != None):
      res = session.get(site_addr)
      if (res.status_code != 200):
          print("[!] parsing Error!! Error Code: ", str(res.status_code))
          exit(0)
  
      bs = BeautifulSoup(res.text, "html.parser")
  
      if (tag_flag):
          print ("[o] Tag Counts : ", len(tag))
          for v in bs.find_all(tag):
              print(v)
      else:
          print(bs)
  ```

- 토르 서비스가 켜져있는지 체크 하는 방법

  ```bash
  # Tor 데몬 Off
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --tor_check
  [-] tor is not running!
  # Tor 데몬 On
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --tor_check
  [+] tor is running!
  ```

- 내 아이피 주소 체크하는 방법

  ```bash
  # Tor 데몬 Off
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --ip
  [-] tor is not running!
  [-] tor is not running!
  Public IP: {
    "origin": "123.111.183.171"
  }
  # Tor 데몬 On
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --ip
  [+] tor is running!
  [+] tor is running!
  Tor IP: {
    "origin": "185.220.102.245"
  }
  ```


- tor 데몬을 이용해서 실제 다크웹 파싱 예시

  ```bash
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --url "http://zqktlwi4fecvo6ri.onion/wiki/index.php/Main_Page"
  [+] tor is running!
  
  <style>
  @media print {
   .noprint,
   .catlinks,
   .magnify,
   .mw-cite-backlink,
   .mw-editsection,
   .mw-editsection-like,
   .mw-hidden-catlinks,
   .mw-indicators,
   .mw-redirectedfrom,
   .patrollink,
   .usermessage,
   #column-one,
   #footer-places,
   #mw-navigation,
      ...
  ```


  - 위에서 파싱한 다크웹은 hidden wiki라고 알려진 다크웹 사이트들에 대한 정보들을 모아둔 위키이다. (안위험함)

- tor 데몬을 이용해서 실제 다크웹 파싱 예시 + 태그 추가

  ``` bash
  oz1ng@LAPTOP-6F0C4A2N:~/bob/darkweb$ python3 my_parser.py --url "http://zqktlwi4fecvo6ri.onion/wiki/index.php/Main_Page" --tag h3
  [+] tor is running!
  [o] Tag Counts :  2
  <h3><span id="Belarussian_/_Белорусский"></span><span class="mw-headline" id="Belarussian_.2F_.D0.91.D0.B5.D0.BB.D0.BE.D1.80.D1.83.D1.81.D1.81.D0.BA.D0.B8.D0.B9">Belarussian / Белорусский</span></h3>
  <h3><span id="Finnish_/_Suomi"></span><span class="mw-headline" id="Finnish_.2F_Suomi">Finnish / Suomi</span></h3>
  <h3><span id="French_/_Français"></span><span class="mw-headline" id="French_.2F_Fran.C3.A7ais">French / Français</span></h3>
  <h3><span id="German_/_Deutsch"></span><span class="mw-headline" id="German_.2F_Deutsch">German / Deutsch</span></h3>
  <h3><span id="Greek_/_ελληνικά"></span><span class="mw-headline" id="Greek_.2F_.CE.B5.CE.BB.CE.BB.CE.B7.CE.BD.CE.B9.CE.BA.CE.AC">Greek / ελληνικά</span></h3>
  ...
  ```

  

- 이렇게 계속 파서를 만들어서 기존의 데이터와 비교를 하면서 다크웹에 새로운 데이터가 올라왔는지 파싱한다.