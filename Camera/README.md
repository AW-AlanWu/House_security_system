# 照相機增加嘗試
>> 由於可能失敗，所以設計成就算失敗也可以將此區塊的功能拆解掉的模式!
* 主要設計成讓OV7670將照片以binary的狀態將資料以ESP015用UDP傳送給對應電腦的UDP port
* 而電腦負責處理UDP port的程式是一支python程式，接收後再將binary轉圖檔後再將照片轉移至apache http sever的根目錄下
* 圖檔在apache伺服器底下，直接以圖檔顯示在網頁上，最後由APP inventor直接存取此網址，將圖片於手機秀出

而要達成以上效果，大概步驟如下：
1. 讓OV7670能夠以任意格式輸出圖檔
2. 設定OV7670輸出資料格式
3. 撰寫PC端程式透過Arduino取得相機資料 
4. 測試於PC上顯示相機圖片
5. 架設靜態網頁網站存放相機圖片
6. APP Invertor顯示圖片
7.  APP Invertor觸發相機拍攝

##目前進度
>>接線已成功，並和ESP015合體!詳情如下

電阻顏色：
10K歐姆-棕黑黑紅.
4.7K歐姆-黃紫黑棕.

![alt text](https://github.com/AW-AlanWu/House_security_system/Camera/wire.PNG)

>>目前因技術問題無法採以上順序處理XD

	* 已達成讓OV7670輸出圖檔的功能，卻不知道輸出的是不是真的是圖檔XDD，目前是binary的形式
	* 目前希望可以將資料以byte的陣列直接UDP傳送出去，卻因為圖片的byte數高達11265，所以記憶體爆炸XD，以及OV7670的鮑率高達1000000，所以很難和ESP015配合，目前仍待解決
	* 目前如何發送UDP也是個問題，由於檔案太大中途害怕遺失，確保的方式也有待設計
	* Apache Sever已能架設並設定port並且運作(比想像的簡單!?一個衝動還寫了操作教學)
	* UDP的Python程式已可以互相自己溝通，也可自我定義port(比想像中的簡..?)
	
* 參考資料
>> [OV7670 DataSheet](http://web.mit.edu/6.111/www/f2016/tools/OV7670_2006.pdf "Title")
>> [camera_module OV7670 fourm](https://forum.arduino.cc/index.php?topic=535819.0 "Title")
>> [How to Use OV7670 Camera Module with Arduino​](https://circuitdigest.com/microcontroller-projects/how-to-use-ov7670-camera-module-with-arduino "Title")
>> [python實現的udp協議Server和Client程式碼例項](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/374245/ "Title")
>> [Simple python udp server](https://gist.github.com/majek/1763628 "Title")