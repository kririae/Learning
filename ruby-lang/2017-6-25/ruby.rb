=begin
回顾一下
ruby的self代表接收器对象
和python的self相同
true
false
nil
__FILE__
__LINE__

=end

#三元运算符
a = true ? 1 : 2
p a

=begin
1	str % arg
使用格式规范格式化字符串。如果 arg 包含一个以上的替代，那么 arg 必须是一个数组。如需了解更多格式规范的信息，请查看"内核模块"下的 sprintf。
2	str * integer
返回一个包含 integer 个 str 的新的字符串。换句话说，str 被重复了 integer 次。
3	str + other_str
连接 other_str 到 str。
4	str << obj
连接一个对象到字符串。如果对象是范围为 0.255 之间的固定数字 Fixnum，则它会被转换为一个字符。把它与 concat 进行比较。
5	str <=> other_str
把 str 与 other_str 进行比较，返回 -1（小于）、0（等于）或 1（大于）。比较是区分大小写的。
6	str == obj
检查 str 和 obj 的相等性。如果 obj 不是字符串，则返回 false，如果 str <=> obj，则返回 true，返回 0。
7	str =~ obj
根据正则表达式模式 obj 匹配 str。返回匹配开始的位置，否则返回 false。
8

9	str.capitalize
把字符串转换为大写字母显示。
10	str.capitalize!
与 capitalize 相同，但是 str 会发生变化并返回。
11	str.casecmp
不区分大小写的字符串比较。
12	str.center
居中字符串。
13	str.chomp
从字符串末尾移除记录分隔符（$/），通常是 \n。如果没有记录分隔符，则不进行任何操作。
14	str.chomp!
与 chomp 相同，但是 str 会发生变化并返回。
15	str.chop
移除 str 中的最后一个字符。
16	str.chop!
与 chop 相同，但是 str 会发生变化并返回。
17	str.concat(other_str)
连接 other_str 到 str。
18	str.count(str, ...)
给一个或多个字符集计数。如果有多个字符集，则给这些集合的交集计数。
19	str.crypt(other_str)
对 str 应用单向加密哈希。参数是两个字符长的字符串，每个字符的范围为 a.z、 A.Z、 0.9、 . 或 /。
20	str.delete(other_str, ...)
返回 str 的副本，参数交集中的所有字符会被删除。
21	str.delete!(other_str, ...)
与 delete 相同，但是 str 会发生变化并返回。
22	str.downcase
返回 str 的副本，所有的大写字母会被替换为小写字母。
23	str.downcase!
与 downcase 相同，但是 str 会发生变化并返回。
24	str.dump
返回 str 的版本，所有的非打印字符被替换为 \nnn 符号，所有的特殊字符被转义。
25	str.each(separator=$/) { |substr| block }
使用参数作为记录分隔符（默认是 $/）分隔 str，传递每个子字符串给被提供的块。
26	str.each_byte { |fixnum| block }
传递 str 的每个字节给 block，以字节的十进制表示法返回每个字节。
27	str.each_line(separator=$/) { |substr| block }
使用参数作为记录分隔符（默认是 $/）分隔 str，传递每个子字符串给被提供的 block。
28	str.empty?
如果 str 为空（即长度为 0），则返回 true。
29	str.eql?(other)
如果两个字符串有相同的长度和内容，则这两个字符串相等。
30	str.gsub(pattern, replacement) [or]
str.gsub(pattern) { |match| block }
返回 str 的副本，pattern 的所有出现都替换为 replacement 或 block 的值。pattern 通常是一个正则表达式 Regexp；如果是一个字符串 String，则没有正则表达式元字符被解释（即，/\d/ 将匹配一个数字，但 '\d' 将匹配一个反斜杠后跟一个 'd'）。
31	str[fixnum] [or] str[fixnum,fixnum] [or] str[range] [or] str[regexp] [or] str[regexp, fixnum] [or] str[other_str]
使用下列的参数引用 str：参数为一个 Fixnum，则返回 fixnum 的字符编码；参数为两个 Fixnum，则返回一个从偏移（第一个 fixnum）开始截至到长度（第二个 fixnum）为止的子字符串；参数为 range，则返回该范围内的一个子字符串；参数为 regexp，则返回匹配字符串的部分；参数为带有 fixnum 的 regexp，则返回 fixnum 位置的匹配数据；参数为 other_str，则返回匹配 other_str 的子字符串。一个负数的 Fixnum 从字符串的末尾 -1 开始。
32	str[fixnum] = fixnum [or] str[fixnum] = new_str [or] str[fixnum, fixnum] = new_str [or] str[range] = aString [or] str[regexp] =new_str [or] str[regexp, fixnum] =new_str [or] str[other_str] = new_str ]
替换整个字符串或部分字符串。与 slice! 同义。
33	str.gsub!(pattern, replacement) [or] str.gsub!(pattern) { |match| block }
执行 String#gsub 的替换，返回 str，如果没有替换被执行则返回 nil。
34	str.hash
返回一个基于字符串长度和内容的哈希。
35	str.hex
把 str 的前导字符当作十六进制数字的字符串（一个可选的符号和一个可选的 0x），并返回相对应的数字。如果错误则返回零。
36	str.include? other_str [or] str.include? fixnum
如果 str 包含给定的字符串或字符，则返回 true。
37	str.index(substring [, offset]) [or]
str.index(fixnum [, offset]) [or]
str.index(regexp [, offset])
返回给定子字符串、字符（fixnum）或模式（regexp）在 str 中第一次出现的索引。如果未找到则返回 nil。如果提供了第二个参数，则指定在字符串中开始搜索的位置。
38	str.insert(index, other_str)
在给定索引的字符前插入 other_str，修改 str。负值索引从字符串的末尾开始计数，并在给定字符后插入。其意图是在给定的索引处开始插入一个字符串。
39	str.inspect
返回 str 的可打印版本，带有转义的特殊字符。
40	str.intern [or] str.to_sym
返回与 str 相对应的符号，如果之前不存在，则创建符号。
41	str.length
返回 str 的长度。把它与 size 进行比较。
42	str.ljust(integer, padstr=' ')
如果 integer 大于 str 的长度，则返回长度为 integer 的新字符串，新字符串以 str 左对齐，并以 padstr 作为填充。否则，返回 str。
43	str.lstrip
返回 str 的副本，移除了前导的空格。
44	str.lstrip!
从 str 中移除前导的空格，如果没有变化则返回 nil。
45	str.match(pattern)
如果 pattern 不是正则表达式，则把 pattern 转换为正则表达式 Regexp，然后在 str 上调用它的匹配方法。
46	str.oct
把 str 的前导字符当作十进制数字的字符串（一个可选的符号），并返回相对应的数字。如果转换失败，则返回 0。
47	str.replace(other_str)
把 str 中的内容替换为 other_str 中的相对应的值。
48	str.reverse
返回一个新字符串，新字符串是 str 的倒序。
49	str.reverse!
逆转 str，str 会发生变化并返回。
50	str.rindex(substring [, fixnum]) [or]
str.rindex(fixnum [, fixnum]) [or]
str.rindex(regexp [, fixnum])
返回给定子字符串、字符（fixnum）或模式（regexp）在 str 中最后一次出现的索引。如果未找到则返回 nil。如果提供了第二个参数，则指定在字符串中结束搜索的位置。超出该点的字符将不被考虑。
51	str.rjust(integer, padstr=' ')
如果 integer 大于 str 的长度，则返回长度为 integer 的新字符串，新字符串以 str 右对齐，并以 padstr 作为填充。否则，返回 str。
52	str.rstrip
返回 str 的副本，移除了尾随的空格。
53	str.rstrip!
从 str 中移除尾随的空格，如果没有变化则返回 nil。
54	str.scan(pattern) [or]
str.scan(pattern) { |match, ...| block }
两种形式匹配 pattern（可以是一个正则表达式 Regexp 或一个字符串 String）遍历 str。针对每个匹配，会生成一个结果，结果会添加到结果数组中或传递给 block。如果 pattern 不包含分组，则每个独立的结果由匹配的字符串、$& 组成。如果 pattern 包含分组，每个独立的结果是一个包含每个分组入口的数组。
55	str.slice(fixnum) [or] str.slice(fixnum, fixnum) [or]
str.slice(range) [or] str.slice(regexp) [or]
str.slice(regexp, fixnum) [or] str.slice(other_str)
See str[fixnum], etc.
str.slice!(fixnum) [or] str.slice!(fixnum, fixnum) [or] str.slice!(range) [or] str.slice!(regexp) [or] str.slice!(other_str)
从 str 中删除指定的部分，并返回删除的部分。如果值超出范围，参数带有 Fixnum 的形式，将生成一个 IndexError。参数为 range 的形式，将生成一个 RangeError，参数为 Regexp 和 String 的形式，将忽略执行动作。
56	str.split(pattern=$;, [limit])
基于分隔符，把 str 分成子字符串，并返回这些子字符串的数组。
如果 pattern 是一个字符串 String，那么在分割 str 时，它将作为分隔符使用。如果 pattern 是一个单一的空格，那么 str 是基于空格进行分割，会忽略前导空格和连续空格字符。
如果 pattern 是一个正则表达式 Regexp，则 str 在 pattern 匹配的地方被分割。当 pattern 匹配一个玲长度的字符串时，str 被分割成单个字符。
如果省略了 pattern 参数，则使用 $; 的值。如果 $; 为 nil（默认的），str 基于空格进行分割，就像是指定了 ` ` 作为分隔符一样。
如果省略了 limit 参数，会抑制尾随的 null 字段。如果 limit 是一个正数，则最多返回该数量的字段（如果 limit 为 1，则返回整个字符串作为数组中的唯一入口）。如果 limit 是一个负数，则返回的字段数量不限制，且不抑制尾随的 null 字段。
57	str.squeeze([other_str]*)
使用为 String#count 描述的程序从 other_str 参数建立一系列字符。返回一个新的字符串，其中集合中出现的相同的字符会被替换为单个字符。如果没有给出参数，则所有相同的字符都被替换为单个字符。
58	str.squeeze!([other_str]*)
与 squeeze 相同，但是 str 会发生变化并返回，如果没有变化则返回 nil。
59	str.strip
返回 str 的副本，移除了前导的空格和尾随的空格。
60	str.strip!
从 str 中移除前导的空格和尾随的空格，如果没有变化则返回 nil。
61	str.sub(pattern, replacement) [or]
str.sub(pattern) { |match| block }
返回 str 的副本，pattern 的第一次出现会被替换为 replacement 或 block 的值。pattern 通常是一个正则表达式 Regexp；如果是一个字符串 String，则没有正则表达式元字符被解释。
62	str.sub!(pattern, replacement) [or]
str.sub!(pattern) { |match| block }
执行 String#sub 替换，并返回 str，如果没有替换执行，则返回 nil。
63	str.succ [or] str.next
返回 str 的继承。
64	str.succ! [or] str.next!
相当于 String#succ，但是 str 会发生变化并返回。
65	str.sum(n=16)
返回 str 中字符的 n-bit 校验和，其中 n 是可选的 Fixnum 参数，默认为 16。结果是简单地把 str 中每个字符的二进制值的总和，以 2n - 1 为模。这不是一个特别好的校验和。
66	str.swapcase
返回 str 的副本，所有的大写字母转换为小写字母，所有的小写字母转换为大写字母。
67	str.swapcase!
相当于 String#swapcase，但是 str 会发生变化并返回，如果没有变化则返回 nil。
68	str.to_f
返回把 str 中的前导字符解释为浮点数的结果。超出有效数字的末尾的多余字符会被忽略。如果在 str 的开头没有有效数字，则返回 0.0。该方法不会生成异常。
69	str.to_i(base=10)
返回把 str 中的前导字符解释为整数基数（基数为 2、 8、 10 或 16）的结果。超出有效数字的末尾的多余字符会被忽略。如果在 str 的开头没有有效数字，则返回 0。该方法不会生成异常。
70	str.to_s [or] str.to_str
返回接收的值。
71	str.tr(from_str, to_str)
返回 str 的副本，把 from_str 中的字符替换为 to_str 中相对应的字符。如果 to_str 比 from_str 短，那么它会以最后一个字符进行填充。两个字符串都可以使用 c1.c2 符号表示字符的范围。如果 from_str 以 ^ 开头，则表示除了所列出的字符以外的所有字符。
72	str.tr!(from_str, to_str)
相当于 String#tr，但是 str 会发生变化并返回，如果没有变化则返回 nil。
73	str.tr_s(from_str, to_str)
把 str 按照 String#tr 描述的规则进行处理，然后移除会影响翻译的重复字符。
74	str.tr_s!(from_str, to_str)
相当于 String#tr_s，但是 str 会发生变化并返回，如果没有变化则返回 nil。
75	str.unpack(format)
根据 format 字符串解码 str（可能包含二进制数据），返回被提取的每个值的数组。format 字符由一系列单字符指令组成。每个指令后可以跟着一个数字，表示重复该指令的次数。星号（*）将使用所有剩余的元素。指令 sSiIlL 每个后可能都跟着一个下划线（_），为指定类型使用底层平台的本地尺寸大小，否则使用独立于平台的一致的尺寸大小。format 字符串中的空格会被忽略。
76	str.upcase
返回 str 的副本，所有的小写字母会被替换为大写字母。操作是环境不敏感的，只有字符 a 到 z 会受影响。
77	str.upcase!
改变 str 的内容为大写，如果没有变化则返回 nil。
78	str.upto(other_str) { |s| block }
遍历连续值，以 str 开始，以 other_str 结束（包含），轮流传递每个值给 block。String#succ 方法用于生成每个值。
=end
=begin
1	array & other_array
返回一个新的数组，包含两个数组中共同的元素，没有重复。
2	array * int [or] array * str
返回一个新的数组，新数组通过连接 self 的 int 副本创建的。带有 String 参数时，相当于 self.join(str)。
3	array + other_array
返回一个新的数组，新数组通过连接两个数组产生第三个数组创建的。
4	array - other_array
返回一个新的数组，新数组是从初始数组中移除了在 other_array 中出现的项的副本。
5	str <=> other_str
把 str 与 other_str 进行比较，返回 -1（小于）、0（等于）或 1（大于）。比较是区分大小写的。
6	array | other_array
通过把 other_array 加入 array 中，移除重复项，返回一个新的数组。
7	array << obj
把给定的对象附加到数组的末尾。该表达式返回数组本身，所以几个附加可以连在一起。
8	array <=> other_array
如果数组小于、等于或大于 other_array，则返回一个整数（-1、 0 或 +1）。
9	array == other_array
如果两个数组包含相同的元素个数，且每个元素与另一个数组中相对应的元素相等（根据 Object.==），那么这两个数组相等。
10	array[index] [or] array[start, length] [or]
array[range] [or] array.slice(index) [or]
array.slice(start, length) [or] array.slice(range)
返回索引为 index 的元素，或者返回从 start 开始直至 length 个元素的子数组，或者返回 range 指定的子数组。负值索引从数组末尾开始计数（-1 是最后一个元素）。如果 index（或开始索引）超出范围，则返回 nil。
11	array[index] = obj [or]
array[start, length] = obj or an_array or nil [or]
array[range] = obj or an_array or nil
设置索引为 index 的元素，或者替换从 start 开始直至 length 个元素的子数组，或者替换 range 指定的子数组。如果索引大于数组的当前容量，那么数组会自动增长。负值索引从数组末尾开始计数。如果 length 为零则插入元素。如果在第二种或第三种形式中使用了 nil，则从 self 删除元素。
12	array.abbrev(pattern = nil)
为 self 中的字符串计算明确的缩写集合。如果传递一个模式或一个字符串，只考虑当字符串匹配模式或者以该字符串开始时的情况。
13	array.assoc(obj)
搜索一个数组，其元素也是数组，使用 obj.== 把 obj 与每个包含的数组的第一个元素进行比较。如果匹配则返回第一个包含的数组，如果未找到匹配则返回 nil。
14	array.at(index)
返回索引为 index 的元素。一个负值索引从 self 的末尾开始计数。如果索引超出范围则返回 nil。
15	array.clear
从数组中移除所有的元素。
16	array.collect { |item| block } [or]
array.map { |item| block }
为 self 中的每个元素调用一次 block。创建一个新的数组，包含 block 返回的值。
17	array.collect! { |item| block } [or]
array.map! { |item| block }
为 self 中的每个元素调用一次 block，把元素替换为 block 返回的值。
18	array.compact
返回 self 的副本，移除了所有的 nil 元素。
19	array.compact!
从数组中移除所有的 nil 元素。如果没有变化则返回 nil。
20	array.concat(other_array)
追加 other_array 中的元素到 self 中。
21	array.delete(obj) [or]
array.delete(obj) { block }
从 self 中删除等于 obj 的项。如果未找到相等项，则返回 nil。如果未找到相等项且给出了可选的代码 block，则返回 block 的结果。
22	array.delete_at(index)
删除指定的 index 处的元素，并返回该元素。如果 index 超出范围，则返回 nil。
23	array.delete_if { |item| block }
当 block 为 true 时，删除 self 的每个元素。
24	array.each { |item| block }
为 self 中的每个元素调用一次 block，传递该元素作为参数。
25	array.each_index { |index| block }
与 Array#each 相同，但是传递元素的 index，而不是传递元素本身。
26	array.empty?
如果数组本身没有包含元素，则返回 true。
27	array.eql?(other)
如果 array 和 other 是相同的对象，或者两个数组带有相同的内容，则返回 true。
28	array.fetch(index) [or]
array.fetch(index, default) [or]
array.fetch(index) { |index| block }
尝试返回位置 index 处的元素。如果 index 位于数组外部，则第一种形式会抛出 IndexError 异常，第二种形式会返回 default，第三种形式会返回调用 block 传入 index 的值。负值的 index 从数组末尾开始计数。
29	array.fill(obj) [or]
array.fill(obj, start [, length]) [or]
array.fill(obj, range) [or]
array.fill { |index| block } [or]
array.fill(start [, length] ) { |index| block } [or]
array.fill(range) { |index| block }
前面三种形式设置 self 的被选元素为 obj。以 nil 开头相当于零。nil 的长度相当于 self.length。最后三种形式用 block 的值填充数组。block 通过带有被填充的每个元素的绝对索引来传递。
30	array.first [or]
array.first(n)
返回数组的第一个元素或前 n 个元素。如果数组为空，则第一种形式返回 nil，第二种形式返回一个空的数组。
31	array.flatten
返回一个新的数组，新数组是一个一维的扁平化的数组（递归）。
32	array.flatten!
把 array 进行扁平化。如果没有变化则返回 nil。（数组不包含子数组。）
33	array.frozen?
如果 array 被冻结（或排序时暂时冻结），则返回 true。
34	array.hash
计算数组的哈希代码。两个具有相同内容的数组将具有相同的哈希代码。
35	array.include?(obj)
如果 self 中包含 obj，则返回 true，否则返回 false。
36	array.index(obj)
返回 self 中第一个等于 obj 的对象的 index。如果未找到匹配则返回 nil。
37	array.indexes(i1, i2, ... iN) [or]
array.indices(i1, i2, ... iN)
该方法在 Ruby 的最新版本中被废弃，所以请使用 Array#values_at。
38	array.indices(i1, i2, ... iN) [or]
array.indexes(i1, i2, ... iN)
该方法在 Ruby 的最新版本中被废弃，所以请使用 Array#values_at。
39	array.insert(index, obj...)
在给定的 index 的元素前插入给定的值，index 可以是负值。
40	array.inspect
创建一个数组的可打印版本。
41	array.join(sep=$,)
返回一个字符串，通过把数组的每个元素转换为字符串，并使用 sep 分隔进行创建的。
42	array.last [or] array.last(n)
返回 self 的最后一个元素。如果数组为空，则第一种形式返回 nil。
43	array.length
返回 self 中元素的个数。可能为零。
44	array.map { |item| block } [or]
array.collect { |item| block }
为 self 的每个元素调用一次 block。创建一个新的数组，包含 block 返回的值。
45	array.map! { |item| block } [or]
array.collect! { |item| block }
为 array 的每个元素调用一次 block，把元素替换为 block 返回的值。
46	array.nitems
返回 self 中 non-nil 元素的个数。可能为零。
47	array.pack(aTemplateString)
根据 aTemplateString 中的指令，把数组的内容压缩为二进制序列。指令 A、 a 和 Z 后可以跟一个表示结果字段宽度的数字。剩余的指令也可以带有一个表示要转换的数组元素个数的数字。如果数字是一个星号（*），则所有剩余的数组元素都将被转换。任何指令后都可以跟一个下划线（_），表示指定类型使用底层平台的本地尺寸大小，否则使用独立于平台的一致的尺寸大小。在模板字符串中空格会被忽略。
48	array.pop
从 array 中移除最后一个元素，并返回该元素。如果 array 为空则返回 nil。
49	array.push(obj, ...)
把给定的 obj 附加到数组的末尾。该表达式返回数组本身，所以几个附加可以连在一起。
50	array.rassoc(key)
搜索一个数组，其元素也是数组，使用 == 把 key 与每个包含的数组的第二个元素进行比较。如果匹配则返回第一个包含的数组。
51	array.reject { |item| block }
返回一个新的数组，包含当 block 不为 true 时的数组项。
52	array.reject! { |item| block }
当 block 为真时，从 array 删除元素，如果没有变化则返回 nil。相当于 Array#delete_if。
53	array.replace(other_array)
把 array 的内容替换为 other_array 的内容，必要的时候进行截断或扩充。
54	array.reverse
返回一个新的数组，包含倒序排列的数组元素。
55	array.reverse!
把 array 进行逆转。
56	array.reverse_each {|item| block }
与 Array#each 相同，但是把 array 进行逆转。
57	array.rindex(obj)
返回 array 中最后一个等于 obj 的对象的索引。如果未找到匹配，则返回 nil。
58	array.select {|item| block }
调用从数组传入连续元素的 block，返回一个数组，包含 block 返回 true 值时的元素。
59	array.shift
返回 self 的第一个元素，并移除该元素（把所有的其他元素下移一位）。如果数组为空，则返回 nil。
60	array.size
返回 array 的长度（元素的个数）。length 的别名。
61	array.slice(index) [or] array.slice(start, length) [or]
array.slice(range) [or] array[index] [or]
array[start, length] [or] array[range]
返回索引为 index 的元素，或者返回从 start 开始直至 length 个元素的子数组，或者返回 range 指定的子数组。负值索引从数组末尾开始计数（-1 是最后一个元素）。如果 index（或开始索引）超出范围，则返回 nil。
62	array.slice!(index) [or] array.slice!(start, length) [or]
array.slice!(range)
删除 index（长度是可选的）或 range 指定的元素。返回被删除的对象、子数组，如果 index 超出范围，则返回 nil。
63	array.sort [or] array.sort { | a,b | block }
返回一个排序的数组。
64	array.sort! [or] array.sort! { | a,b | block }
把数组进行排序。
65	array.to_a
返回 self。如果在 Array 的子类上调用，则把接收参数转换为一个 Array 对象。
66	array.to_ary
返回 self。
67	array.to_s
返回 self.join。
68	array.transpose
假设 self 是数组的数组，且置换行和列。
69	array.uniq
返回一个新的数组，移除了 array 中的重复值。
70	array.uniq!
从 self 中移除重复元素。如果没有变化（也就是说，未找到重复），则返回 nil。
71	array.unshift(obj, ...)
把对象前置在数组的前面，其他元素上移一位。
72	array.values_at(selector,...)
返回一个数组，包含 self 中与给定的 selector（一个或多个）相对应的元素。选择器可以是整数索引或者范围。
73	array.zip(arg, ...) [or]
array.zip(arg, ...){ | arr | block }
把任何参数转换为数组，然后把 array 的元素与每个参数中相对应的元素合并。
=end

a = [1,2,3,4]
b = [2,3,4,5]
p a&b#=>[2,3,4]
p a+b#=>[1,2,3,4,2,3,4,5]
p a*2#=>[1,2,3,4,1,2,3,4]
p a-b#=>[1]
p a <=> b#=>-1
p a | b#=>基本等于并集有序数组而非集合
p a << 1#基本等于在末尾加入1
p a << b
p a << '1'
p a == b
p a[1,3]#=>python : [1:3]
p a[(1..2)]#=>a[range]
p a.slice(10)
a[2] = '2'
p a
#这种方法自己脑洞
p a.assoc(1)
p a.at(-1)#=>基本等于负数索引
a.clear#=>移除所有元素
a = [1,2,3,4]
p a.map!{|i| i+1}#=>[2,3,4,5]
p a.collect!{|i| i-1}
a = [nil,nil,nil,1,2,3,4]
p a#=>[nil, nil, nil, 1, 2, 3, 4]
a.compact!
p a#=>[1, 2, 3, 4]
p a[-1]#=>本身支持负数引导w
p a.reduce(:+)
class Array
  def plus a
    self + a
  end
end
b = Array.new(10){|i| i+1}
p b.plus [1,2,3,4]

a = [1,2,3,4]
p (a.include? 3)
p a
puts 1 unless a = [1,2,3,4]
p a.reverse!
p a.reject!{|i| not i == 1}
p a.length


