计算公式： 第j位失配，第1～j-1个字符记为字符串S:
next[j] = S最长相等前后缀+1,特别的，next[1]=0

对于字符串google:
j=1, S=❌， next[1]=0
j=2, S=g, next[2] = 1
j=3, S=go, 前缀={g},后缀={o},最长相等前后缀={},next[3]=0+1=1
j=4, S=goo，前缀={g,go},后缀={o,oo}，最长相等前后缀={},next[4]=0+1=1
j=5, S=goog，前缀={g,go,goo},后缀={g,og,oog}，最长相等前后缀={g},next[5]=1+1=2,
j=6, S=googl，前缀={g,go,goo,goog},后缀={l,gl,ogl,oogl},最长相等前后缀={o},next[6]=0+1=1,
所以google的next数组为：{0,1,1,1,2,1}
