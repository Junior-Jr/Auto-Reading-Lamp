# Auto Reading Lamp :bulb::books:


:pencil: โปรเจกต์นี้เป็นส่วนหนึ่งของวิชา Computer Programming (รหัสวิชา 06016315)
คณะเทคโนโลยีสารสนเทศ สาขาเทคโนโลยีสารสนเทศ 
สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง

:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## Introduction
โปรเจกต์นี้ได้สร้างชิ้นงานขึ้นมา โดยการใช้โมดูลต่างๆและเขียนโปรแกรมลงบนบอร์ดไมโครคอนโทรเลอร์ เพื่อให้โคมไฟแสดงระดับความสว่างที่เหมาะสมต่อสายตาในการอ่านหนังสือ/การทำงานที่ต้องใช้สายตา คือแสดงค่าประมาณ 500 lux [Visit Light Levels](https://www.noao.edu/education/QLTkit/ACTIVITY_Documents/Safety/LightLevels_outdoor+indoor.pdf). 


:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## Software :computer:
Arduino Software (IDE)

:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## Hardware :electric_plug:
* Arduino UNO R3
* Module PIR 
* Module LDR 
* Relay 
* LCD 16*1
* Resistor 10k 
* Variable Resistor 10k Dimmer 
* Lamp
* Warm White 220v 60 Watt Bulb

:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## How To Work :question::question:
เมื่อเสียบปลั๊กการใช้งาน เมื่อเกิดเสียงปี๊บขึ้นมาคือแสดงถึงการเริ่มต้นการใช้งาน ซึ่ง PIR Motion Sensor ตรวจจับการเคลื่อนไหวของผู้ใช้งาน(โดยถ้า PIR มีค่าเกิน 600 แสดงถึงมีผู้ใช้งานอยู่) จากนั้นจะควบคุมการทำงานของโคมไฟในการปรับระดับความสว่างที่เหมาะสมต่อสายตา โดยใช้เซนเซอร์วัดแสง(LDR)ในการรับแสงจากสภาพแวดล้อมในขณะนั้นๆ ว่าสว่างพอหรือไม่ โดยมีเงื่อนไขดังตารางข้างล่าง จากนั้นจึงทำการปรับค่าความสว่างของโคมไฟโดยใช้ตัวต้านทานปรับค่าได้(Variable Resistor 10k Dimmer )

ความสว่าง | ข้อความบนจอ LCD
------------ | -------------
ความสว่างน้อยไป | Increase
ความสว่างมากไป | Decrease
ความสว่างพอดี | Good To Read


:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## Team Members
:bust_in_silhouette: นาย ปภาวิทย์ พัทธสิริวิโชติ รหัสนักศึกษา 60070045 (@prapawity)

:bust_in_silhouette:นาย พสธร จิตปรีดากร รหัสนักศึกษา 60070059 (@Junior-Jr)

:bust_in_silhouette:นางสาว พัณณิตา เหมโก รหัสนักศึกษา 60070061 (@Pannita2212)


:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:
## Assistant Teacher
:busts_in_silhouette: ผศ. ดร. กิติ์สุชาติ พสุภา
    :busts_in_silhouette: ผศ. ดร. ปานวิทย์ ธุวะนุติ
    

