# encoding = utf-8
require "redcarpet"
require "pygments"
module MakeDown
  class Render < Redcarpet::Render::HTML
    #TODO
    def block_code code, language
      Pygments.highlight code, lexer: "html"
    end
  end
  @render = Render.new ({
      :filter_html => true,
      :hard_wrap => true,
  })
  @options = {
      :autolink => true,
      :no_intra_emphasis => true,
      :fenced_code_blocks => true,
      :lax_html_blocks => true,
      :strikethrough => true,
      :superscript => true,
      :tables => true
  }

  def render_html makedown_text
    markdown = Redcarpet::Markdown.new @render, @options
    markdown.render makedown_text
  end

  module_function :render_html
end

