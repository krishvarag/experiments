#JDK INSTALLATION


# SSL CERT 

```
..\bin\keytool -list -keystore ..\lib\security\cacerts
password : changeit

# To add cert
keytool -import  -alias KrishCA -keystore ..\lib\security\cacerts - file krish.cer
```