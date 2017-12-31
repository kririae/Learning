# use https://github.com/Binaryify/NeteaseCloudMusicApi
require 'net/http'
require 'pp'
require 'json'
require 'open-uri'
require 'net/smtp'

class NeteaseCloudMusic

  attr_accessor :phone, :password, :login_info
  attr_reader :host, :port

  def initialize(phone, password)
    # Net::HTTP.version_1_2
    @host = "127.0.0.1"
    @phone = phone
    @password = password
    @login_info = get "/login/cellphone?phone=#{phone}&password=#{password}" # login
  end
  def get url, port = 3000
    Net::HTTP.start @host, port do |http|
      response = http.get url
      return response.body
    end
  end
  def get_albums id, limit = 50
    get "/artist/album?id=#{id}&limit=#{limit}"
  end
  def daily_sign
    get "/daily_signin"
  end
  def get_daily_fm
    pfm = JSON.parse get "/personal_fm"
    return nil if pfm["code"] == 405
    pfm["data"].each do |i| puts i end
  end
end

class C93
  attr_accessor :netcm
  def initialize
    @netcm = NeteaseCloudMusic.new "", ""
  end
  def new_album id
    ret = JSON.parse @netcm.get_albums id
    album_name = ret["hotAlbums"][0]["name"]
    if(album_name != "秘封活動記録-祝-Original Soundtrack")
      curr_dir = File.dirname __FILE__.to_s
      curr_dir += "/#{album_name}"
      puts curr_dir
      # puts curr_dir
      Dir.mkdir album_name unless Dir.exist? curr_dir
      req = URI.parse ret["hotAlbums"][0]["picUrl"]
      data = open ret["hotAlbums"][0]["picUrl"] do |f| f.read end
      File.open curr_dir + "/#{album_name}.jpg", "wb" do |f| f.write data end
    end
  end
end

# c93 = C93.new
# c93.new_album 21981

netcm = NeteaseCloudMusic.new "", ""
n = Network.new
n.send_email "kriaeth"
