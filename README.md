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

