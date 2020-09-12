# vk-audio-url-decoder
## Компиляция:
**linux** - g++ -shared -fPIC vk-audio-url-decoder.cpp -o lib.so -rdynamic 

**windows** - с помощью visual studio
## Методы:
- **void** setUserId (`long` user_id):

	задаёт **`user_id`** - ***ID*** пользователя, который получает аудио
- **char*** decode (`const char *` url,`int` user_id=-1,`boolean` need_mp3=true):  
Декодирует ссылку из зашифрованной в играбельную

 `url` - ссылка на закодированную аудиозапись, по типу 
>  https://vk.com/mp3/audio_api_unavailable.mp3?extra=AgnMALPWBKHJDc9UEwvdwhnHwgHdn21ZBI1lC21nBeD3nMCVmMLPrtLQB2rIy2SVAveWvw9Ls2u2zhDdCtHHDdy1ytrJyu9ulv9eEdP3yJHPzwuX...

`user_id` - передавать id пользователя ( или вызвать метод `setUserId` )

`need_mp3` - если `true`, то возвращается ссылка на **mp3** аудио, иначе возвращается ссылка на **m3u8**


- **char*** toMP3(`const char *` url):
конвертирует ссылку **m3u8** в **mp3**
`url` - ссылка на аудиозапись в формате **m3u8**, по типу 
> https://cs1-59v4.vkuseraudio.net/p21/dce69e69fda/9de954d0b39405/index.m3u8?extra=7CrE-4wK3XICdOO4uXaCO-UbqTYXxtPCX9mzW9hxijr7uPHJCRYC3jTtPcMGki...

## Пример на питоне:

```python
import ctypes
lib = ctypes.CDLL(r'build/ubuntu/lib.so')#путь к скомпилированному файлу 
# на windows - build/windows/x64.dll или  build/windows/x32.dll 
# в зависимости от разрядности запускаемой версии 
#x64:bool = sys.maxsize==9223372036854775807
lib.decode.restype=ctypes.c_char_p;
lib.toMP3.restype=ctypes.c_char_p;  #устанавливаем результат функций

lib.setUserId(100)#id пользователя, получившиго ссылку
url_not_decrypted = "https://vk.com/mp3/audio_api_unavailable.mp3?extra=ewiowe..."#ссылка
url_decrypted = lib.decode(url_not_decrypted.encode()).decode();#декодируем
print("ссылка получена:",url_decrypted);
```

