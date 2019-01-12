title: 「学习笔记」HTML Review
author: kririae
date: 2019-01-05 14:30:52
tags:
---
<h1 id="_title">HTML Note</h1>

<!--more-->

`img`标签的`alt`/`src`属性，代表$\text{alternative}$和$\text{source}$。顺带一提，还有`width`和`height`属性。
下面的图片是找不到的，所以会显示`alt`后的`Alternative`。
以下代码`<img src="/qwq.img" alt="Alternative">`将会显示为: <img src="/qwq.jpg" alt="Alternative"/>

`br`标签的意思自然是$\text{breakline}$，`pre`标签是保留原本文字，比如说以下代码
```html
<p>
q
w
<br/>
q?
</p>
```
与
```html
<pre>
q
w
<br/>
q
?
</pre>
```
将会表示为:
<p>
q
w
</br>
q?
</p>
<pre>
q
w
</br>
q
?
</pre>

`pre`标签内除$\text{elements}$外的形式将会被保留。

<table>
<tbody><tr>
<th>Tag</th>
<th>Description</th>
</tr>
<tr>
<td>&lt;b&gt;</td>
<td>Defines bold text</td>
</tr>
<tr>
<td>&lt;em&gt;</td>
<td>Defines emphasized text&nbsp;</td>
</tr>
<tr>
<td>&lt;i&gt;</td>
<td>Defines italic text</td>
</tr>
<tr>
<td>&lt;small&gt;</td>
<td>Defines smaller text</td>
</tr>
<tr>
<td>&lt;strong&gt;</td>
<td>Defines important text</td>
</tr>
<tr>
<td>&lt;sub&gt;</td>
<td>Defines subscripted text</td>
</tr>
<tr>
<td>&lt;sup&gt;</td>
<td>Defines superscripted text</td>
</tr>
<tr>
<td>&lt;ins&gt;</td>
<td>Defines inserted text</td>
</tr>
<tr>
<td>&lt;del&gt;</td>
<td>Defines deleted text</td>
</tr>
<tr>
<td>&lt;mark&gt;</td>
<td>Defines marked/highlighted text</td>
</tr>
</tbody>
</table>

总之，都是首字母就是了，背起来也不复杂。

让我们尝试定义一个可爱的小按钮？
`<a style="border: 2px solid white; padding: 2px; border-radius: 4px; text-decoration: none; color: white;" href="#">Button</a>`
<a style="border: 2px solid white; padding: 2px; border-radius: 4px; text-decoration: none; color: white;" href="#">Button</a>
可惜$\text{stackedit}$貌似不支持自定义$\text{css}$。

`a`标签中有一个`target`属性，值为`_blank`，`_self`，`_parent`，`_top`。

$\text{CSS}$的`background-image`属性也可以用于很多标签，比如说`p`:
`<p style="background-image: url('text.img')">test</p>`

接下来是表格属性。
在前文的代码里我们已经见过表格属性了，接下来我们来熟悉它:
```html
<table>
<tr>
<th>qwq1</th>
</tr>
<tr>
<td>qwq</td>
</tr>
</table>
```
这是一个简单的表格
但是，当我们加上一些神奇的魔法
```html
<style>
table, th, td {
	border: 1px solid black;
	border-collapse:  collapse;
}
</style>
```
$\text{collapse}:$ 坍缩
就是把多根`border`组合成一根。
剩下的属性就简单介绍了
`colspan`，`rowspan`，横向合并和纵向合并。
如果要让表格稍微分开点，`th, td { padding: 2px; }`即可。

`ul`和`ol`在制作表格式区块时很有用。
比如说制作导航栏，我们用`ul`来实现。至于横向，我们可以用`li { float: left; }`来控制。纵向则是`li { float: inline; }`。
`ol`的`type`属性有很多，这里不细细列举了。
<ol type="1">  
<li>Coffee</li>  
<li>Tea</li>  
<li>Milk</li>  
</ol>

<ol type="A">  
<li>Coffee</li>  
<li>Tea</li>  
<li>Milk</li>  
</ol>

<ol type="a">  
<li>Coffee</li>  
<li>Tea</li>  
<li>Milk</li>  
</ol>

<ol type="I">  
<li>Coffee</li>  
<li>Tea</li>  
<li>Milk</li>  
</ol>

下面是一些看起来没卵用实际上很有用的`container`。
主要用于$\text{CSS}$，$\text{JavaScript}$配置时。
`div`，`span`。

`class`属性主要归类用，并且可以如此定义:
`<div class="name age"></div>`
相比来说，`id`是类似身份证号的东西，特征是“唯一”。

但是`id`有个很牛逼的地方，可以进行跳转?!

比如说，我在这篇文档开头加上这么一行代码。

实际上已经加了。
`<h1 id="_title">HTML Note</h1>`，如果你点击下面的`a`标签，将会回到顶部。`<a href="#_title">回到顶部</a>` 
<a href="#_title">回到顶部</a>。

`iframe`标签很有意思了。
`<iframe src="https://oi.yuyuko.cc" width="100%"></iframe>`
比如说这是我的博客...
<iframe src="https://oi.yuyuko.cc" width="100%"></iframe>

加入`script`标签表示`js`代码。

<h2 id="ResponsiveWebDesign">HTML响应式设计</h2>

首先，$\text{CSS}$的`max-width`属性可以用于响应式设计，比如:
<img style="max-width: 100%; max-height: auto;" src="https://i.loli.net/2018/12/30/5c285f1e2bcb5.jpg"/>

同时，`viewport`
`<p style="font-size:10vw;">Hello World</p>`，`vw`表示`viewport height`，也表示当前浏览器的高度。



