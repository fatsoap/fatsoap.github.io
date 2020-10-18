<link href="./style.css" rel="stylesheet" />

# Chapter 1 : Introduction

## Page 1-2 Roadmap
---
### Protocol : 
* 通訊協定
### Edge : 
* 網路的邊邊 :  PC , Phone, Sever
### Core : 
Router
### Access net , Phyical media : 
* 如何接到網路 => 有線、無線
* 連線的材料 => 銅、光纖、電磁波
### ISP structure : 
* ISP(網際網路服務供應商)
* 網路是由階層式的方式連接，介紹連接的方法
### Preformance :
* 網路封包loss、delay，如何控制loss & delay
### Protocol layers , service models :
* protolcol , service 模組化

## Page 1-4 What’s the Internet: "nuts and bolts" view
---
### Millions of connected computing devices :
* hosts = end-systems (PC, phone , sever)
* running network apps
### Communication links : 
* fiber, copper, radio, satellite
* transmission rate = <strong>bandwidth (頻寬)
### Routers : 
* 路由器，判斷封包傳送路徑
### Protocols :
* 網路通訊協定 : TCP , IP , HTTP , FTP , PPP
### Internet = "network of networks" : 
* loosely hierarchical 階層式 
* NAT : a area have a public IP that connect to multiple private IP in this area
### Internet standards : 
* RFC , IETF : 制定標準協會

## Page 1-6 What’s the Internet: a "service" view
---
### Communication Infrastructure
* 分散式設備應用 : Web, email, games, e-commerce, database., voting, file (MP3) sharing <br/>
* 服務 : 
>1. connectionless : 無須建連線 (UTP) => don't care loss , delay <br>
>2. connection=oriented : 要先建連線 (TCP) => 減少loss , delay

## Page 1-7 What’s a protocol?
---
### Network protocols :
* Define : <strong>format , order , response actions</strong>(遵循一定格式、順序、回應方法)
* Example : 
>* PC -> TCP connection(req) -> Server
>* PC <- TCP connection(res) <- Server
>* PC -> Get 'http://www.abc.com/pic.png'(req) -> Server
>* PC <- File(res) <- Server

## Page 1-10 Network edge
---
### End systems (hosts):
* run application : web , email (at edge of network)
### Client/Sever modol :
* client host requests and receives response from alway-on sever
### Peer-2-Peer moudole :
* client to client (no sever)

## Page 1-12 Connection-oriented service
---
### Goal : data transfer between end systems
#### TCP service (Transmission Control Protocol)
1. handshaking(建連線) : call and setup (prepare for) data transfer ahead of time
2. reliable , in ordered byte stream data transfer
* loss: acknowledgements and retransmissions(確認收到不然重新傳送)
3. flow control (流量控制)
* sender won’t overwhelm receiver
4. congestion control (網路擁擠控制)
* senders “slow down sending rate” when network congested(掉封包時)

## Page 1-13 Connectionless service
---
### Goal : data transfer between end systems
#### UDP (User Datagram Protocol) connectionless service
1. unreliable data transfer (可能掉封包)
2. no flow control (沒有流量控制)
3. no congestion control (沒有網路擁擠控制)

## Page 1-12 & 1-13 Summary
---
### App using TCP (send important file): 
HTTP(web) , FTP(file transfer) , Telnet(remote login) , SMTP(email)
### App using UDP (don't care loss): 
Streaming media(music, video) , DNS , telephony(skype)

## Page 1-15 Network Core
---
### Mesh of interconnected routers 
*  every router have more than one connect to other router
### The fundamental question : how is data transferred through net?
#### Circuit Switching (沒有競爭) : 
1. End-end resources reserved for “call” (路徑保留專屬資源)
* link bandwidth,  switch capacity (保留頻寬，router 承載量)
* dedicated resources: no sharing (保留的資源不分享給其他連線)
* call setup required (要事先預約)
2. network resources (e.g.. bandwidth) divided into "pieces"(資源切片)
* pieces allocated to calls (切片根據需求分配)
* resource piece idle if not used by owning call (專屬切片no sharing)
* divide by <strong>frequency division</strong> or <strong>time division</strong>
3. FDMA (frequency division)
* 平分頻寬，每個使用時間一樣(可使用頻寬減少)
4. TDMA (time division)
* 平分時間，每個使用頻寬一樣(可使用時間減少)
#### Packet-switching (互相競爭) : 
1. Each end-end data stream divided into packets (傳送的資料切割成封包)
* user A, B packets share network resources (沒有保留資源)
* each packet uses full link bandwidth  (用全部頻寬)
2. Resource contention (誰搶到資源就誰用) :
* aggregate resource demand can exceed amount available (傳送需求大於通道供給)
* congestion: packets queue, wait for link use (網路擁擠 , 存到buffer等到link有位子)
* store and forward: packets move one hop at a time(封包排隊等link有空位)
3. statistical multiplexing (統計多重化) :
* 封包排隊的演算法，根據流量等等分配
4. Message Segmenting (封包切割) :
* 適量切割，再利用pipeline減少delay
5. Path selection algorithms(shorter path) :
>* select less router , more bandwidth .....
>1. Datagram network : (封包走不固定路線)
>* every packet have destination address (封包目的地)
>* router may change during session (邊傳邊看怎走)
>2. virtual circuit network (封包走固定路線): 
>* fixed path determined at call setup time (call一次來確認路徑怎走)
>* routers maintain per-call state (router維護每個call的tag路徑)
>* each packet carries tag (virtual circuit ID)，router 根據tag分配路徑

#### Curcuit switching V.S Packet switching :
1. For 1 Mbps link & each user : 100 kbps when active , active 10% of time :
* circuit switching : 10 users
* packet switching : 35 users (probability > 10 users active at same time less than 0.0004)
2. When to use circuit and packet :
* Packet-switching : Great for bursty data (爆發性資料) use resource sharing , no call setup
* Circuit-switching : Great for important file transfer, (TCP協定避免過於擁擠時會掉封包)

<img src='./assets/1-26.png' />

## Page 1-28 Access networks
---
### How to connect end systems to edge router?
1. Residential access nets (一般民用)
* Point to point access
>* Dialup via modem(數據機、電話線撥接) :
>> Slow , can't be always on;
>* ADSL (asymmetric digital subscriber line) :
>>* 上傳和下載速度不一樣
>>* Use FDM (frequency divide)
* Cable modems
>* HFC: hybrid fiber coaxial cable(銅軸電纜、光纖)
>* Asymmetric(上傳和下載速度不一樣)
>* network of cable and fiber attaches homes to ISP router
>>* shared access to router among home
>>* issues: congestion, dimensioning

2. Company access : Local area networks (LAN)
* Ethernet : 
>1. shared or dedicated(專用) link connects end system and router
>2. Deployment(部署) : institutions(機構), home(家), company (公司) 

3. Wireless access networks
* End systems connect to routers via base station
>* base station(基地台) also known as “access point”

4. Home networks (Typical home network components):
* Lv1. Router
* Lv2. ADSL or cable modem (public IP)
* Lv3. small router(private IP) , include : firewall , NAT
* Lv4. Ethernet
* Lv5. wireless access point(路由器)

<img src="./assets/1-28.png" />

## Page 1-39 Physical Media
---
### Bit :
* 傳輸最基本單位
### Physical link :
1. Guided media(實體材料): Copper, Fiber, Coax
>1. Twisted Pair(TP) 雙絞線
>* 兩條絞在一起，抵銷電磁波干擾

<img src="./assets/1-39.png" />

>2. Coaxial cable(銅軸電纜)
>* bidirectional(雙向)
>* baseband (single channel) , broadband (multiple channels)

<img src="./assets/1-40-1.png" />

>3. Fiber optic cable:
>* glass fiber carrying light pulses, each pulse a bit
>* high-speed
>* low error rate(不被電磁波干擾)
>* repeater (訊號放大器，延長訊號傳遞)

<img src="./assets/1-40-2.png" />

2. Unguided media(非實體材料) : Radio
* signal carried in electromagnetic spectrum(電磁波)
* no physical “wire”
* bidirectional
* propagation environment effects:
>1. reflection (訊號反射)
>2. obstruction by objects (訊號被阻擋)
>3. interference (訊號干擾)
* Radio link types :
>1. Terrestrial  microwave (微波)
>* e.g. up to 45 Mbps channels
>2. LAN (Wifi .. )
>* 2Mbps, 11Mbps, 54Mbps, 108 Mbps
>3. Wide-area (cellular 蜂窩狀)
>* 手機4G , 5G : hundreds of kbps
>4. Satellite
>* up to 50Mbps channel (or multiple smaller channels)
>* 270 msec end-end delay(延遲長)
>* geosynchronous versus low-earth-orbit satellites (LEOS低軌衛星)















