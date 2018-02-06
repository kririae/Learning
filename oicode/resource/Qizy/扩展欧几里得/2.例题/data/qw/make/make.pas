// 程序名：makedata
// 功能：利用EXE自动产生测试数据
// 作者：曾贵胜

program make;
uses
  dos;
const
  filename= 'qw';            //文件名,不同程序此处需要修改
  fileexe=  filename+'.exe';  //标程可执行文件名
  filein= filename+'.in';     //标准输入文件
  fileout=filename+'.out' ;   //标准输出文件

var
  f,ff:text;               //文件变量
  m1,n1,x1,y1,l1,n,i,j,a,b,c :longint;
  nn:array[1..10] of longint=(30,50,80,100,2000,30000,400000,500000,6000000,70000000);  //10个输入文件的范围
  m,min,mout:string;

begin
  for n:=1 to 10 do begin  //循环10次,依次产生10组测试数据
    str(n,m); // 得到1组文件序号
    min:=filename+m+'.in';  //加序号m的输入文件名
    mout:=filename+m+'.out';  //加序号m的输出文件名

    assign(output,filein);rewrite(output);  //产生标准输入文件

//--------------  不同题目，只需要修改此处 -------------------------------------

   // writeln(nn[n]);  //在输入文件第一行写入本组输入文件的n值
    randomize;
    l1:=random(nn[n]);
    x1:=random(l1 div 2);
    y1:=random(l1 div 2);
    m1:=random(nn[n]);
    if m1>100 then m1:=m1 div 100
      else if m1>1 then m1:=m1 div 10;
    n1:=random(nn[n] div 2);
    if n1>100 then n1:=n1 div 100
      else if n1>10 then n1:=n1 div 10;

    write(x1,' ',y1,' ',m1,' ',n1,' ',l1);
    writeln;
//-----------------------------------------------------------------------------

    close(output);    //关闭文件，,产生1个标准输入文件*.in
    exec(fileexe,''); //调用并执行外部标准exe程序,产生1个标准输出文件*.out

    assign(f,filein);
    rename(f,min);    //输入文件更名，加上序号

    assign(ff,fileout);
    rename(ff,mout);  //输出文件更名，加上序号
  end;
end.




