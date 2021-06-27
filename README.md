# Conway-Game-of-Life
生命游戏(Game of life)
 ## 定义(`definition`)
* 这是一个零玩家的游戏，由一张很大的正方形网格棋盘组成,有棋子的格子为黑色，代表生命，没有棋子的格子代表死亡。
* (This is a zero-player game consisting of a large square grid board.The grid with chess pieces is black, representing life, and the grid without chess pieces represents death.)
## 规则(`Rules`)
* 每个回合结束后，生命会有所更新，更新规则有4条：
* (After each round, the life will be updated. There are 4 update rules:)
* * 生命害怕孤独(Life is afraid of loneliness)
* * * 当回合结束时，生命周围的生命少于2个，则生命在回合结束时死亡
* * 生命讨厌拥挤(Life hates crowding)
* * * 如果一个生命周围的生命超过了3个，则它在回合结束时也死亡
* * 生命会繁殖(Life will reproduce)
* * * 如果一个死格子周围有三个生命，则它在回合结束时，获得生命
* * 生命可以延续(Life can continue)
* * * 如果一个回合结束时，生命周围有2-3个生命，则它保持原样

## 稳定结构(Stable structure)
部分稳定结构
![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s1.png)  ![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s2.png)

![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s4.png) ![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s5.png)

![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s7.png) ![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s8.png)

## 震荡结构(Oscillating structure)
部分震荡结构，红绿灯和脉冲星
![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s12.png)              ![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s11.png)
## 移动结构(Mobile structure)
部分移动结构，滑翔机枪，连续输出子弹
![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/s13.png)
## you can try more by yourself
### * 既可以使用旁边的案例，也可以使用鼠标自主绘制想要的图形
![](https://github.com/djh-sudo/Conway-Game-of-Life/blob/main/src/demo.gif)
## reference
[混乱博物馆](https://www.bilibili.com/video/BV1zx41187v3/?spm_id_from=333.788.recommend_more_video.-1)
## For more
### 如果我们的计算机的每一个寄存器的每一位都可以看做生命游戏里的一个个体,那么....
