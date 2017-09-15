# coding: utf-8
require "./lib/html_init"
class Combine
  @@style = %Q{
<style>
  body{
    margin: 0 auto;
    background-color: #1D1F21;

/*	--------- FONT FAMILY --------
 	following are some optional font families. Usually a family
	is safer to choose than a specific font,
	which may not be on the users computer		*/
    font-family:Georgia, Palatino, serif;
/    font-family:"Book Antiqua", Palatino, serif;
/    font-family:Arial, Helvetica, sans-serif;
/    font-family:Tahoma, Verdana, Geneva, sans-serif;
/    font-family:Courier, monospace;
/    font-family:"Times New Roman", Times, serif;

/*	-------------- COLOR OPTIONS ------------
 	following are additional color options for base font
	you could uncomment another one to easily change the base color
	or add one to a specific element style below         */
    color: #ffffff; /* dark gray not black */
/    color: #ffffff; /* black */
/    color: #ffffff; /* medium gray  black */
/    color: #ffffff; /* very light gray */
/    color: #ffffff;

    line-height: 1;
/    max-width: 960px;
    max-width: 800px;
    padding: 30px;
    font-size: 18px;
}


p   {
/    font-size: 22px;
    line-height: 150%;
/    max-width: 540px;
    max-width: 960px;
    font-weight: 400;
     color: #ffffff
}


h1, h2, h3, h4 {
/    color: #2bbc8a;
    font-weight: 400;
}

h2, h3, h4, h5, p {
    margin-bottom: 25px;
    padding: 0;
}

h1 {
    margin-bottom: 10px;
    font-size:300%;
    padding: 0px;
    fvont-variant:small-caps;
    color: #2bbc8a;
}

h2 {
    font-size:150%;
    margin: 24px 0 6px;
}

h3 {
    font-size:120%
}
h4 {
    font-size:100%;
    font-variant:small-caps;

}
h5 {
    font-size:80%;
    font-weight: 100;
}

h6 {
    font-size:80%;
    font-weight: 100;
    color:red;
    font-variant:small-caps;
}
a {
    color: grey;
    margin: 0;
    padding: 0;
    vertical-align: baseline;
}
a:hover {
    text-decoration: blink;
    color: green;
}
a:visited {
    color: black;
}
ul, ol {
    padding: 0;
    margin: 0px 0px 0px 50px;
}
ul {
    list-style-type: square;
    list-style-position: inside;

}

li {
     line-height:150%;
     color: #ffffff;
}
li ul, li ul {
    margin-left: 24px;
}

pre {
    padding: 0px 24px;
    max-width: 800px;
    white-space: pre-wrap;
}
code {
    font-family: Consolas, Monaco, Andale Mono, monospace;
    line-height: 1.5;
    font-size: 13px;
}
aside {
    display: block;
    float: right;
    width: 390px;
}
blockquote {
    border-left:.5em solid #eee;
    padding: 0 1em;
    margin-left:0;
    max-width: 476px;
}
blockquote  cite {
 /   font-size:14px;
    line-height:20px;
    color:#bfbfbf;
}
blockquote cite:before {
    content: '�4  A0';
}

blockquote p {
    color: #666;
    max-width: 460px;
}
hr {
/    width: 540px;
    text-align: left;
    margin: 0 auto 0 0;
    color: #999;
}

</style>
  }
  class <<self
    def render context: nil, style: nil, title: "imageSaving", link: nil
      %Q{
<!doctype html>
<html>
<head>

<meta charset='UTF-8'><meta name='viewport' content='width=device-width initial-scale=1'>
<title>#{title}</title>
#{link}
      #{style}

</head>
<body class='index' >
  #{context}
</body>
</html>
}
    end

    def outPut md
      context = MakeDown.render_html md
      render context: context, style: @@style
    end
  end
end
file = File.open "./index.html", "w"
path, = ARGV
res = nil
if File.exist? path
  File.open path, "r" do |f|
    res = f.readlines.join("")
  end
else
  puts "#{path} file is not exist"
end
p res
file.write Combine.outPut res
