# encoding= utf-8
p "init tocmd..."
res = `gem install tocmd`
ERROR =<<ERROR
ERROR:  While executing gem ... (Gem::FilePermissionError)
  You don't have write permissions for the /var/lib/gems/2.3.0 directory.
ERROR
if res ==ERROR
  pus 'please run "sudo gem install tocmd"'
end
