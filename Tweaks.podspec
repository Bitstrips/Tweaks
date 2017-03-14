Pod::Spec.new do |spec|
  spec.name         = 'Tweaks'
  spec.version      = '2.1.0'
  spec.license      =  { :type => 'BSD' }
  spec.homepage     = 'https://github.com/facebook/Tweaks'
  spec.authors      = { 'Grant Paul' => 'tweaks@grantpaul.com', 'Kimon Tsinteris' => 'kimon@mac.com' }
  spec.summary      = 'Easily adjust parameters for iOS apps in development.'
  spec.source       = { :git => 'https://github.com/facebook/Tweaks.git', :tag => '2.1.0' }
  spec.source_files = 'FBTweak/*.{h,m}'
  spec.requires_arc = true
  spec.social_media_url = 'https://twitter.com/fbOpenSource'
  spec.framework = 'MessageUI'
  
  spec.ios.deployment_target = '6.0'

  spec.subspec 'Debug' do |subspec|
    subspec.source_files = 'FBTweak/*.{h,m}'
    subspec.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) FB_TWEAK_ENABLED=1' }
  end
end
