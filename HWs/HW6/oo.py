import base64

encoded_string = "CIMWBDWQPWTPAMSDDAJPTKPKJKPWMAZPWJKNEPWDWJMWQAXTPFIMRWVWRAZQKDKQIPEKXTRKPWXQEYIRRNWSXDJWQWTWXPWTKXTYIRRWBPWXTPFWDWJZAJUKXQWAZCKDDRIQKPIAXMKRAXCYIPFWBDKXTIXCPFWMQADWAZQKDKNIRIPIWMIXMSDDAJPAZIXQJWKMIXCREXWYKXTIXXAVKPIVWKDDRIQKPIAXMKQJAMMPFWJWKRUMAZYIJWRWMMQAXXWQPIVIPEQACXIPIAXMWXMIXCKXTIUKCIXCCFICFWJZJWGSWXQIWMYIRRWXKNRWUSQFZKMPWJMKUDRIXCJKPWMIXKTTIPIAXPADJAVITIXCMICXIZIQKXPRENWPPWJPFJASCFDSPKXTFICFWJTKPKJKPWMPFWQAUNIXKPIAXAZMSNUUYKVWWCYKVWRWXCPFMMUKRRWJPFKXAXWUIRRIUWPWJKXTPFWSMWAZZJWGSWXQEMWRWQPIVIPEPATWPWJUIXWJWRKPIVWWRWQPJAUKCXWPIQKNMAJDPIAXJKPWMIMWBDWQPWTPARWKTPADAPWXPIKRREMICXIZIQKXPKTVKXQWMIXYIJWRWMMMWXMIXCPWQFXARACEKTTIPIAXKRREYFWJWKMPFWKTTIPIAXAZUANIRWWTCWQAUDSPIXCIMKDAIXPAZQAXMITWJKPIAXKMKXKTTIPIAXPACXWPYAJOMUANIRWWTCWQAUDSPIXCYIRRNWNSIRPIXPAKRRCXWPYAJOMWTCWKXTQAJWQAUDSPIXCYIRRNWQAUWUSQFUAJWMWKURWMMREIXPWCJKPWTKMDKJPAZKQAUNIXWTQAUUSXIQKPIAXMQAUDSPKPIAXIXZJKMPJSQPSJWZJKUWYAJONEPFWPIUWCXWPYAJOMKJWTWDRAEWTPFIMYIRRDJAVITWUKXEDAPWXPIKRKTVKXPKCWMKMCPWQFXARACENWQAUWMADWJKPIAXKRIXQRSTIXCIUDJAVWTKQQWMMPAKJPIZIQIKRIXPWRRICWXQWQKDKNIRIPIWM"

decoded_string = base64.b64decode(encoded_string)

print(decoded_string)