Pod::Spec.new do |s|
  s.name                = "Mobilogics"
  s.version             = "5.1.0"
  s.summary             = "Mobilogics Barcode SDK"
  s.description         = <<-DESC
	You need to add an array item named [Supported external accessory protocols]
	in your Info.plist. Then add four string items into this array as follows:
	Item 0: tw.com.mobilogics.ipdt380
	Item 1: tw.com.mobilogics.iscan
	Item 2: tw.com.mobilogics.ascan
	Item 3: tw.com.mobilogics.iPDT5
  DESC
  s.homepage            = "http://www.mobilogics.com.tw"
  s.license             = { :type => 'Commercial' }
  s.license             = { :type => 'Commercial', :text => <<-LICENSE
Copyright (c) 2011-2013 Mobilogics International Co., Ltd.
  • All rights reserved.
  • Mobilogics International Co., Ltd. copyrights the Mobilogics SDK.
  • No part of the Mobilogics SDK may be reproduced in any form or means without the prior written consent of Mobilogics International Co., Ltd.
LICENSE
}
  s.author              = { "Mobilogics" => "mobilogicsusa@gmail.com" }
  s.source              = { :git => "https://github.com/martinrybak/Mobilogics.git", :tag => "5.1.0" }
  s.platform            = :ios, '6.0'
  s.libraries           = 'stdc++.6'
  s.vendored_frameworks = 'Barcode.framework', 'MobilogicsCore.framework'
  s.framework           = 'ExternalAccessory'
  s.requires_arc        = true
end
