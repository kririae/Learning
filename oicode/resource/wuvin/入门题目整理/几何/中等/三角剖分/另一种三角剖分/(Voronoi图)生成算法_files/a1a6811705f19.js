
Do(function(){
  var cookieCfg={key:"ap",cookie:"1"},$doubanTip=$("#doubanapp-tip"),data={};function hideDoubanTip(){if(!$doubanTip.length){return}$doubanTip.hide();data[cookieCfg.key]=cookieCfg.cookie;set_cookie(data)}$doubanTip.delegate("a","click",hideDoubanTip);if(!get_cookie(cookieCfg.key)){$doubanTip.show()}var popup;var nav=$("#db-global-nav");var more=nav.find(".bn-more");function handleShowMoreActive(c){var a=$(c.currentTarget);var b=a.parent();hideDoubanTip();if(popup){popup.parent().removeClass("more-active");if($.contains(b[0],popup[0])){popup=null;return}}b.addClass("more-active");popup=b.find(".more-items");popup.trigger("moreitem:show")}nav.delegate(".bn-more, .top-nav-reminder .lnk-remind","click",function(a){a.preventDefault();handleShowMoreActive(a);return}).delegate(".lnk-doubanapp","mouseenter",function(b){var a=$(this);if(!a.parent().hasClass("more-active")){handleShowMoreActive(b)}}).delegate(".top-nav-doubanapp","mouseleave",function(){var b=$(this);var a=b.find(".lnk-doubanapp");if(popup){b.removeClass("more-active");if($.contains(b[0],popup[0])){popup=null}}});$(document).click(function(a){if($(a.target).closest(".more-items").length||$(a.target).closest(".more-active").length){return}if(popup){popup.parent().removeClass("more-active");popup=null}});
});

  Do(function(){
    var nav = $('#db-nav-sns');
    var inp=$("#inp-query"),label=inp.closest(".nav-search").find("label");if("placeholder" in inp[0]){label.hide();inp.attr("placeholder",label.text())}else{if(inp.val()!==""){label.hide()}inp.parent().click(function(){inp.focus();label.hide()}).end().focusin(function(){label.hide()}).focusout(function(){if($.trim(this.value)===""){label.show()}else{label.hide()}}).keydown(function(){label.hide()})}inp.parents("form").submit(function(){if(!$.trim(inp.val()).length){return false}});nav.find(".lnk-more, .lnk-account").click(function(b){b.preventDefault();var d,a=$(this),c=a.hasClass("lnk-more")?$("#db-productions"):$("#db-usr-setting");if(!c.data("init")){d=a.offset();c.css({"margin-left":(d.left-$(window).width()/2-c.width()+a.width()+parseInt(a.css("padding-right"),10))+"px",left:"50%",top:d.top+a.height()+"px"});c.data("init",1);c.hide();$("body").click(function(g){var f=$(g.target);if(f.hasClass("lnk-more")||f.hasClass("lnk-account")||f.closest("#db-usr-setting").length||f.closest("#db-productions").length){return}c.hide()})}if(c.css("display")==="none"){$(".dropdown").hide();c.show()}else{$(".dropdown").hide()}});
  });
  
  var tagsug_src = "http://img3.douban.com/f/shire/4605e734f440a79abdf4866eb4e6c785dfefbba1/js/lib/tagsug.js";
  Do(function(){window.Do=window.Do||function(i){typeof i=="function"&&setTimeout(i,0)};Do.add_js=function h(j){var i=document.createElement("script");i.src=j;document.getElementsByTagName("head")[0].appendChild(i)};Do.add_css=function a(k,j){var i=document.createElement("link");i.rel="stylesheet";i.href=k;document.getElementsByTagName("head")[0].appendChild(i)};Do.check_js=function d(i,k){var j=i();if(j){k(j)}else{setTimeout(function(){d(i,k)},33)}};var e=$("#inp-query,#search_text"),f,c,g,b={q:"",items:[{num:"",name:"日记",cat:1015},{num:"",name:"成员",cat:1005},{num:"",name:"图片",cat:1025},{num:"",name:"小站",cat:2012},{num:"",name:"电影",cat:1002},{num:"",name:"书籍",cat:1001},{num:"",name:"音乐",cat:1003},{num:"",name:"移动应用",cat:3064}],source:"suggest"};e.one("focus",function(){Do.add_js(tagsug_src);Do.check_js(function(){return $.fn.tagsug&&window.Mustache},function(){c=e.tagsug({wordLimit:30,url:"/j/search_suggest?q=",arrName:"items",max:null,haltLink:false,sugOffset:{left:-6,top:26},listTmpl:'<ul class="sug-kind-search"><li class="title"><a href="javascript: void 0;">搜索 “<span>{{q}}</span>” 相关的：</a></li>{{#items}}<li><a href="/search?cat={{cat}}&q={{q}}&source={{source}}"><span>{{num}}</span>{{name}}</a></li>{{/items}}</ul>',leadChar:"",hideChar:["@"],alignLeft:true,queryIncludingSpace:true,tips:null})._tagsug_api[0];c.on("query",function(j,i){if(i!==f){b.q=f=i;c._anterior_txt="";c.showSug(b)}});g=e.tagsug({max:8,useUid:true,tips:"@某人，直达其个人主页"})._tagsug_api[0];g.on("choose",function(j,i){window.location="/people/"+i+"/"})})});$("body").click(function(j){var i=$("#db-tagsug-list");if(i.length&&!$.contains(i[0],j.target)){i.hide()}if($(j.target).is("#db-tagsug-list .title a")){$(".nav-search form").submit()}})});

    Do(function(){
      (function(){var f=$(document);var e=$("html");var d=$("body");var c={display_close:true};var a=['<div class="ui-overlay-mask" style="display:none;">','<div class="ui-overlay-x"></div>                   ','<div class="ui-overlay-container">                 ','  <a href="#" class="ui-overlay-close" style="display:none;">&times;</a> ','  <div class="hd"></div>                   ','  <div class="bd"></div>                   ',"</div>                                     ","</div>                                     "].join("");var g='<div class="ui-overlay-anchor"></div>';function b(){this.init()}b.prototype={init:function(){var h=this;this.config=c;this.mask=$(a).appendTo(d);this.anchor=$(g).prependTo(d);this.container=this.mask.find(".ui-overlay-container");this.header=this.mask.find(".ui-overlay-container > .hd");this.body=this.mask.find(".ui-overlay-container > .bd");this.bnClose=this.mask.find(".ui-overlay-container > .ui-overlay-close");this.bnClose.click(function(i){i.preventDefault();h.close()});f.delegate(".ui-overlay-mask","click",function(i){if(h.config.forbidden_mask_click){return}if(i.target==h.container[0]||$.contains(h.container[0],i.target)){return}h.close()});f.bind("keyup",function(i){if(h.config.forbidden_hotkey_cancel){return}if(!(/input|textarea/i.test(i.target.tagName))&&i.keyCode===27){h.close()}})},open:function(h,j){var i=this.docTop=f.scrollTop();this.anchor.show().css({marginTop:-i});e.addClass("ui-overlay-show");this.mask.show();if(this.config.display_close){this.bnClose.show()}this.setContent(h||"");if(j){j.call(this)}this.container.trigger("overlay:open")},close:function(){e.removeClass("ui-overlay-show");this.anchor.hide();f.scrollTop(this.docTop);this.mask.hide();this.container.trigger("overlay:close")},bind:function(h,i){this.container.bind(h,i)},setConfig:function(h){this.config=$.extend({},c,h||{})},setHeader:function(h){this.header.html(h)},setContent:function(h){this.body.html(h)}};if(!$.overlay){$.overlay=new b()}})();(function(){var a='<iframe src="javascript:;" frameborder="0" scrolling="no" width="{{width}}" height="{{height}}" name="{{name}}"></iframe>';var b=478;var d=480;function f(i,k,j){var h=curTime=new Date();h.setTime(curTime.getTime()+j);document.cookie=i+"="+escape(k)+((j==null)?"":";expires="+h.toGMTString())+";domain=.douban.com;path=/"}function c(h){if(document.cookie.length>0){var j,i=document.cookie.indexOf(h+"=");if(i!=-1){i=i+h.length+1;j=document.cookie.indexOf(";",i);if(j==-1){j=document.cookie.length}return unescape(document.cookie.substring(i,j))}}return""}var e=function(j,l,k){var i={login:"https://accounts.douban.com/popup/login?source=sns",reg:"https://accounts.douban.com/popup/login?source=sns#popup_register",switch_user:"https://accounts.douban.com/popup/login?source=sns",};var h=$.overlay.body.find("iframe");h.attr("src",i[j])};var g=function(h){return function(l){l.preventDefault();var n=$(this);var i=n.data();var m=i.params?(typeof window[i.params]=="function"?window[i.params].call(this):i.params):null;var j=self.location.href;if(m){j=(j.indexOf("?")+1)?j+"&"+m:j+"?"+m}if(i.width>$("body").width()){i.width=$("body").width()}var k=a.replace("{{width}}",i.width||b).replace("{{height}}",i.height||d).replace("{{name}}",document.location.protocol+"//"+document.location.hostname);if(typeof i.key==="undefined"||!c(i.key)){$.overlay.open(k,function(){h(encodeURIComponent(j),i.source)});if(i.key&&i.cookie&&i.expired){$.overlay.bind("overlay:close",function(){f(i.key,i.cookie,i.expired)})}}}};$(document).delegate(".lnk-show-login","click",g(function(h,i){e("login",h,i)})).delegate(".lnk-show-reg","click",g(function(h,i){e("reg",h,i)})).delegate(".lnk-switch-user","click",g(function(h,i){e("switch_user",encodeURIComponent(h),i)}));$(window).bind("message",function(h){if(h.originalEvent.origin==="https://accounts.douban.com"){$.overlay.body.find("iframe").css("height",h.originalEvent.data)}})})();
    });
    
        Do(function(){
            var DOULIST_ADDITEM="/j/doulist/{doulist_id}/additem";var DOULIST_EDITITEM="/j/doulist/{doulist_id}/edititem";var DOULIST_COMMENT="/j/doulist/{doulist_id}/poke";var DOULIST_CREATE="/j/doulist/add";var DOULIST_LIST="/j/doulist/cat";var DOULIST_SEARCH="/j/doulist/search";var DOULIST_SEARCH_SELF="/j/doulist/search_user_doulists";var DOULIST_GET_ITEM_INFO="/j/doulist/get_item_info";function deferred(){var a={done:[],fail:[]};var b={done:function(c){a.done.push(c);return b},fail:function(c){a.fail.push(c);return b}};return{resolve:function(){var d=0,c;for(;c=a.done[d++];){c.apply(this,arguments)}},reject:function(){var d=0,c;for(;c=a.fail[d++];){c.apply(this,arguments)}},promise:b}}function asyncRequest(a,e,f){var d=deferred();var c=null;var b=(f||"get").toLowerCase();c=$.ajax({url:a,type:b,dataType:"json",data:(b==="post")?$.extend(e,{ck:get_cookie("ck")}):e,error:function(g){d.reject(g)},success:function(g){d.resolve(g)}});d.promise.abort=function(){c&&c.abort()};return d.promise}var addTooltipToDoulistBtn=function(b){if(!get_cookie("ck")){return}var d=/^https?:\/\/\w+\.douban\.com\/link2\/\?url=(\S+)$/i;var i=function(k){var j=k.match(d);return j?decodeURIComponent(j[1]):k};$(document).delegate(".url-doulist-add","click",function(n){n.preventDefault();var j=$(this);var l=i(j.data("url"));var k;var m=dui.Dialog({title:"添加到豆列",width:640,cls:"dialog-doulist dialog-tooltip-loading",content:'<div class="tooltip-text">内容加载中<i class="tooltip-loading-icon"></i></div>'}).open();m.node.find(".dui-dialog-close").click(function(o){k&&k.abort()});k=asyncRequest(DOULIST_GET_ITEM_INFO,{url:l,},"post").done(function(o){if(o.r){m.node.find(".tooltip-text").text(o.error);return}o.cate=(o.kind||"")+"";o.picture=typeof o.images==="string"?o.images:(o.images&&o.images[0])||"";o.id=(o.id||"")+"";m.close();j.doulistDialog(o)}).fail(function(o){m.node.find(".tooltip-text").text("失败啦！再试一次吧")})});var e=85;var a=false;var c="doulist-tooltip-hide";var f=$('<div class="doulist-add-tooltip"><a class="url-doulist-add" ><i></i> 添加到豆列</a><div class="arrow"></div></div>');var h=f.find("a");f.addClass(c);f.appendTo($("body"));var g=function(j){a=setTimeout(function(){f.addClass(c)},e)};$(b).mouseenter(function(k){var j=$(this);f.css({top:j.offset().top-28,left:k.pageX-42});h.data("url",j.attr("href"));clearTimeout(a);f.removeClass(c)}).mouseleave(g);f.mouseenter(function(){clearTimeout(a)}).mouseleave(g)};
            var $regUp = $('#reg-up');
            if ($regUp.length) {
                $regUp.find('.lnk-show-reg').trigger('click');
            }
            addTooltipToDoulistBtn('.note a[rel=nofollow]');
        });
    
            ;(function(e,d,b){var c={weibo:{appkey:""},douban:{},qq:{},qzone:{}};function a(f,g){this.config=b.extend(true,{},c,f);var h=a.serializeOpenGraph();this.pageInfo=b.extend({title:h.title||d.title,url:h.url||d.location.href,pic:(b.type(h.image)==="array"?h.image[0]:h.image)||"",desc:h.description||"",site:h.site_name||""},g)}a.serializeOpenGraph=function(){var g={};b('meta[property^="og:"]').each(function(j,k){k=b(k);var h=k.attr("property").replace(/^og\:/,"");g[h]=k.attr("content")});var f=b('meta[property="og:image"]');if(f.length>1){g.image=f.map(function(h,j){return b(j).attr("content")}).toArray()}return g};a.prototype={constructor:a,set:function(g,f){var h={};h[g]=f;b.extend(this.config,h)},get:function(f){var g=b.extend({},this.pageInfo,this.config[f]);return({douban:{url:"http://www.douban.com/share/service/?"+b.param({href:g.url,name:g.title,image:g.pic,text:g.desc})},weibo:{url:"http://v.t.sina.com.cn/share/share.php?"+b.param({appkey:g.appkey,url:g.url,title:g.title,pic:g.pic})},qq:{url:"http://connect.qq.com/widget/shareqq/index.html?"+b.param({url:g.url,desc:g.title,pics:g.pic,site:g.site})},qzone:{url:"http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?"+b.param({url:g.url,title:g.title,summary:g.desc,pics:g.pic})}})[f]},openInNewWindow:function(i,h){h=h||{};var j=h.width||500,f=h.height||360;var g=b.extend({},{width:j,height:f,toolbar:0,location:0,resizable:1,scrollbars:"yes",left:h.left||(screen.width-j)/2,top:h.top||(screen.height-f)/2},h);e.open(i,"SocialSharing",b.param(g).replace(/&/g,","))}};window.SocialSharing=a})(window,document,jQuery);
            $(function() {
                var sharing = $('.sharing');
                var sharingLayer = sharing.find('.sharing-layer');
                var sharingInfo = self.SHARINGINFO || {};
                var socialSharing = new SocialSharing({
                    weibo: {
                        appkey: '3015934887'
                    }
                }, sharingInfo);
                var logVendors = {
                    'weibo': 'bshare_sina',
                    'qq': 'bshare_qqim',
                    'qzone': 'bshare_qzone'
                };
                var windowFeatures = {
                    qq: { width: 800, height: 600 },
                    qzone: { width: 800, height: 600 }
                };
                var has_qrcode = false;
                function gen_qrcode() {
                    if (!has_qrcode) {
                        sharingLayer.find('.sharing-wechat-qrcode').html('<img src="//img3.doubanio.com/dae/qrgen/v2/' + encodeURIComponent(socialSharing.pageInfo.url) + '.png" alt="扫描二维码" />');
                        has_qrcode = true;
                    }
                }
                sharing.delegate('.sharing-button', 'mouseover', function() {
                    sharingLayer.removeClass('is-hidden');
                    gen_qrcode();
                }).delegate('.sharing-layer', 'mouseleave', function() {
                    sharingLayer.addClass('is-hidden');
                });
                sharingLayer.delegate('[data-share]', 'click', function() {
                    var elem = $(this);
                    var network = elem.data('share');
                    var url = 'http://www.douban.com/link2?type=redir&vendor=' + logVendors[network] + '&url=' + encodeURIComponent(socialSharing.get(network).url);
                    socialSharing.openInNewWindow(url, windowFeatures[network]);
                });
            });
        
var douban_src = '//' + 'www.douban.com';
var fav_type = 'default';
var fav_url = '#';

              Do(function(){
                $("html").delegate(".thing-like-note-fav .btn-fav","click",function(d){var c=$(this);var a=c.attr("data-object_id");var b=c.hasClass("fav-cancel")?1:0;if(c.hasClass("stat-processing")){return}$.ajax({type:b?"delete":"post",url:"/j/note/like_thing_note",data:{note_id:a,ck:get_cookie("ck")},dataType:"json",success:function(e){}})});
              });
            
Do(function() {

var addSimpleTooltip = function(selector, link){
  // only display to logged user
  if (!get_cookie('ck')) return;

  var delayTime = 85;
  var delayTimer = false;

  var hideClassName = 'doulist-tooltip-hide';
  var $tooltip = $('<div class="doulist-add-tooltip">' + link + '<div class="arrow"></div></div>');
  var $btn = $tooltip.find('a');

  $tooltip.addClass(hideClassName);
  $tooltip.appendTo($('body'));

  var delayHideHandler = function(e){
    delayTimer = setTimeout(function(){
        $tooltip.addClass(hideClassName);
    }, delayTime)
  }

  $(selector).mouseenter(function(e){
    var $link = $(this);
    $tooltip.css({
      top: $link.position().top - 28,
      left: e.pageX - 42
    })
    $btn.data('url', $link.attr('href'));

    clearTimeout(delayTimer);
    $tooltip.removeClass(hideClassName);
  }).mouseleave(delayHideHandler);

  $tooltip
    .mouseenter(function(){
    clearTimeout(delayTimer);
    })
    .mouseleave(delayHideHandler)
}

function initPrestoStat(presto_selector, stat_selector) {
  var container = $(presto_selector);
  var presto_words = container.html();
  if (presto_words) {
    var stat_num = $(stat_selector).html();
    if (stat_num) {
      stat_num = parseInt(stat_num);
      var presto_stat_num = parseInt(container.data('count'));
      stat_num = stat_num + presto_stat_num;
      $(stat_selector).html(stat_num + "人");
      addSimpleTooltip(stat_selector, presto_words);
    }
  }
}

initPrestoStat('.presto-like-words', '.fav-num a');
initPrestoStat('.presto-rec-words', '.rec-sec .rec-num');

});

Do(function() {
    $(document).delegate('.mod-usercard .lnk-contact-add', 'click', function(e) {
        e.preventDefault();
        var el = $(this);
        if (el.hasClass('processing')) {
            return;
        }
        el.addClass('processing');
        $.post_withck('/j/contact/addcontact', {
        people: el.data('id'),
        from: el.data('source')
        }, function(r) {
            el.removeClass('processing');
            if (!r.result) {
                return;
            }
            el.replaceWith('<span class="usercard-followed">已关注</span>');
        }, 'json');
    });
});
