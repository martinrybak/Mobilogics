Pod::Spec.new do |s|
  s.name                = "Mobilogics"
  s.version             = "5.1.0"
  s.summary             = "Mobilogics Barcode SDK"
  s.description         = <<-DESC
	You need to add an array item named [Supported external accessory protocols]
	in your Info.plist. Then add four string items into this array as follows:	Item 0: tw.com.mobilogics.ipdt380	Item 1: tw.com.mobilogics.iscan	Item 2: tw.com.mobilogics.ascan	Item 3: tw.com.mobilogics.iPDT5
  DESC
  s.homepage            = "http://www.mobilogics.com.tw"
  s.license             = { :type => 'Commercial' }
  s.author              = { "Mobilogics" => "mobilogicsusa@gmail.com" }
  s.source              = { :git => "https://github.com/martinrybak/Mobilogics.git", :tag => "5.1.0" }
  s.platform            = :ios, '6.0'
  s.libraries           = 'stdc++.6'
  s.vendored_frameworks = 'MobilogicsCore.framework'
  s.frameworks       = 'Barcode', 'MobilogicsCore'
  s.requires_arc        = true
end
