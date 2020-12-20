# Apache http sever架設過程
	1. 將apache-http.zip解壓至特定路徑(如C:/sever/apache24)
	2. 以系統管理員身分開啟command，進入剛才解壓縮目錄裡面的apache24/bin裡面
	3. 輸入： httpd.exe -k install
	4. 以編輯器打開Apache24\conf\httpd.conf，在約38行修改Apache的路徑為剛才解壓的路徑；在約60行的位置修改對外連接的port
	5. 在Apache24\bin，點擊httpd.exe和ApacheMonitor.exe
	6. 以 http://127.0.0.1:<剛才設置埠號>/ 進行測試，目錄apache24\htdocs是伺服器默認的根目錄
	7. 至cmd以ipconfig確認當前ipv4位址，將其代換為127.0.0.1即可
	
>> [apache-http來源](https://www.apachehaus.com/cgi-bin/download.plx "Title")