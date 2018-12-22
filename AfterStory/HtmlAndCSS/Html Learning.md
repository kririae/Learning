# Html Learning

大致格式如下

```html
<!DOCTYPE html>

<html>

<head>
  <title>Title</title>
</head>

<body>
  <p>This is a paragraph</p>
  <br />
</body>

</html>
```

然后，初见几个标签

- `<p>`标签，用于描述某个段落。($\text{paragraph}$)
- `<br />`标签，用于空行。
- `<a>`标签，用于储存超链接。

然后，我们来看“属性”。

`<a href="https://yuyuko.cc">TraceBack's Blog</a>`

效果如下: <a href="https://yuyuko.cc">TraceBack's Blog</a>

接下来列举几个属性

| 属性  | 值               | 描述               |
| ----- | ---------------- | ------------------ |
| class | classname        | 元素的类名         |
| id    | id               | 元素的唯一id       |
| style | style_definition | 元素的inline style |
| title | text             | 元素的额外信息     |

标题通过`<h1> - <h6>`定义

```html
<h1>This is a heading</h1>
<h2>This is a heading</h2>
<h3>This is a heading</h3>
```

然后，问题在于如何插入水平线

`<hr />` 

效果如下:

<hr />

注释呢

`<!-- This is a comment -->`

<!-- This is a comment -->

style初探

<p style="font-family:FiraCode;text-align:center;font-size:30px">font-family:FiraCode;text-align:center;font-size:30px</p>

接下来又是一些文本格式化的标签

| 标签     | 描述     |
| -------- | -------- |
| <b>      | 粗体文字 |
| <big>    | 大号文字 |
| <em>     | 加重文字 |
| <i>      | 斜体字   |
| <small>  | 小号字   |
| <strong> | 加重语气 |
| <sub>    | 下标字   |
| <sup>    | 上标字   |
| <ins>    | 插入     |
| <del>    | 删除字   |

```html
<code>
for (int i = 0; i <= n; ++i) scanf(“%d”, &a[i])
</code>
```

表格由`table`标签定义

`<tr>`标签表示一行

`<td>`标签表示行内内容

```html
<table border="1">
  <tr>
    <th>qwq01</th>
    <th>qwq02</th>
    <th>qwq03</th>
  </tr>
  <tr>
    <td>qwq</td>
    <td>qwq</td>
    <td>qwq</td>
  </tr>
  <tr>
    <td>qwq</td>
    <td>qwq</td>
    <td>qwq</td>
  </tr>
</table>
```

其中`<th>`是加重

`border`是是否加入边框

以下是显示效果:

<table border="1">
  <tr>
    <th>qwq01</th>
    <th>qwq02</th>
    <th>qwq03</th>
  </tr>
  <tr>
    <td>qwq</td>
    <td>qwq</td>
    <td>qwq</td>
  </tr>
  <tr>
    <td>qwq</td>
    <td>qwq</td>
    <td>qwq</td>
  </tr>
</table>

# CSS Learning

CSS语法大致如下:

```
选择器 {
  属性名称: 属性值;
}
```

直接选择:

```css
p {
	...
}
```

`.class`

```html
<p class="traceback">class: traceback</p>

.traceback {
	color: red;
}
```

`#id`

```css
<p id="qwq"></p>

#qwq {
  color: red;
}
```

Class和Id有啥区别?

id不能重名，Class可以重名，就这么简单。id相当于身份证号，class相当与名字，名字可重复，但是身份证号不行。

`*`: 选择所有的。

出现这种情况?

```css
p {
  font-size: 30px;
  color: red;
}
.TraceBack {
  font-size: 30px;
  color: red;
}
```

重复了，好难受啊。

写成这样吧。

```css
p, .TraceBack {
  font-size: 30px;
  color: red;
}
```

如果我们要某个嵌套的标签里的某个元素：

```css
div span {
  font-size: 30px;
}
```

`div`和`span`之间的空格

可以被替代为$>$, $+$。

尾选择器，我们尝试一下：

```css
p:hover {
 color: red;
}
```

就会出现，当你在某个标签表示的上面盘旋的时候，就会启用该css...

css的优先级和权重。

```css
a {
  font-size: 40px;
  color: red;
}

a {
  font-size: 40px;
  color: yellow;
}
```

测试得，是后面的覆盖前面的。和“=赋值”一个道理。

假如说有这么一段html代码:

`main.css`

```css
p {
 color: aqua;
}
```

`main.html`

```html
<!DOCTYPE html>

<html>

<head>
  <link rel="stylesheet" type="text/css" href="main.css">
  <style>
    p {
      color: aquamarine;
    }
  </style>
</head>

<body>
  <p style="color: azure">qwq?</p>
</body>

</html>
```

显示效果很简单:

<p style="color:azure">qwq?</p>

其实本质上并不是一个优先级的问题，而是属性的赋值?本质上就是代码执行的顺序。

但是，还有一个更关键的。

比如说，我们是这么写的

`main.css`

```css
body p {
  color: red;
}

p {
 color: aqua;
}
```

事实上，第一个更明确，则第一个被留下。

继承问题。

## 盒子模型

margin -> border -> padding -> content...

