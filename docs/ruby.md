---
title: Ruby 설치하기
summary: Ruby, jekyll 설치하는 과정
date: 2023-07-28
tags: [ruby, jekyll]
layout: default
nav_order: 100
---

아래 링크에서 다운로드
https://rubyinstaller.org/downloads/

버전 업데이트
```
gem update --system 3.4.17
```

### rake 관련 에러 발생
```
PS D:\Repository\yo-young.github.io> jekyll -v
C:/Ruby32-x64/lib/ruby/gems/3.2.0/gems/bundler-2.3.25/lib/bundler.rb:679:in `rescue in eval_gemspec':  (Bundler::Dsl::DSLError)    
[!] There was an error parsing `Gemfile`: 
[!] There was an error while loading `just-the-docs.gemspec`: No such file or directory - git ls-files -z. Bundler cannot continue.

 #  from D:/Repository/yo-young.github.io/just-the-docs.gemspec:19
 #  -------------------------------------------
 #    spec.add_runtime_dependency "rake", ">= 12.3.1"
 >  end
 #  # coding: utf-8
 #  -------------------------------------------
. Bundler cannot continue.

 #  from D:/Repository/yo-young.github.io/Gemfile:2
 #  -------------------------------------------
 #  
 >  gem "webrick", "~> 1.7"
 #  source "https://rubygems.org"
 #  -------------------------------------------
```

참고 블로그 [링크](https://jeonge.tistory.com/141)  
- git이 설치되지 않았다는 의견  
- 내가 포맷하고 git을 설치하지 않았던가??
- github Desktop은 설치했는데 여기서 설치하는 git과는 연동이 안되는가보다.
- git for Windows를 설치하니 `jekyll -v` 가 잘 작동한다.

### 하지만 여전히 `bundle exec jekyll serve` 작동 안함
```
PS D:\Repository\yo-young.github.io> bundle exec jekyll serve
Could not find webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, webrick-1.7.0, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-4.3.1, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, jekyll-seo-tag-2.8.0, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, addressable-2.8.1, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, i18n-1.12.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, jekyll-sass-converter-2.2.0, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, liquid-4.0.3, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, rouge-4.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, public_suffix-5.0.0, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, concurrent-ruby-1.1.10, listen-3.7.1, listen-3.7.1, listen-3.7.1, listen-3.7.1, listen-3.7.1, listen-3.7.1, listen-3.7.1, listen-3.7.1, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0, unicode-display_width-2.3.0 in locally installed gems
Run `bundle install` to install missing gems.
```

- `bundle install` 수행해봄
- 여전히 실행안되고 있지만 다른 에러 발생
```
PS D:\Repository\yo-young.github.io> bundle exec jekyll serve
Configuration file: D:/Repository/yo-young.github.io/_config.yml
            Source: D:/Repository/yo-young.github.io
       Destination: D:/Repository/yo-young.github.io/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
  Liquid Exception: undefined method `tainted?' for "/":String in 404.html
                    ------------------------------------------------
      Jekyll 4.3.1   Please append `--trace` to the `serve` command 
                     for any additional information or backtrace. 
                    ------------------------------------------------
C:/Ruby32-x64/lib/ruby/gems/3.2.0/gems/liquid-4.0.3/lib/liquid/variable.rb:124:in `taint_check': undefined method `tainted?' for "/":String (NoMethodError)

      return unless obj.tainted?
                       ^^^^^^^^^
```
- `bundle update liquid` 시도
  
# **성공!!**
