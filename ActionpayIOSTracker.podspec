Pod::Spec.new do |s|
  s.name                = 'ActionpayIOSTracker'
  s.author              = { "AdOnWeb LLC" => "devs@actionpay.ru" }
  s.version             = '1.0.2'
  s.summary             = "ActionpayIOSTracker for iOS SDK."
  s.description         = <<-DESC
    SDK для внедрения в сторонние проекты с целью отслеживания установки приложения а также целевых действий пользователей.
  DESC
  s.homepage            = "https://github.com/AdOnWeb/ActionpayIOSTracker"

  s.license             = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2013 - 2014 AdOnWeb LLC, Inc. All rights reserved.
      LICENSE
  }

  s.source              = {
    :git => 'https://github.com/AdOnWeb/ActionpayIOSTracker.git',
    :tag => 'v' + s.version.to_s
  }

  s.platform            = :ios

  s.frameworks          = 'Foundation', 'SystemConfiguration', 'CFNetwork', 'MobileCoreServices', 'Security'
  s.ios.vendored_frameworks = 'ActionpayTracker.framework'

  s.requires_arc        = true
end