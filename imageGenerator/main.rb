def html_gemerator path
  res = nil
  IO.popen "tocmd -f #{path}" do |f|
    res = f.gets
  end
  res
end
# waiting