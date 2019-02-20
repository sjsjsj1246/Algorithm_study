import shutil
import os

src_num = ['1463','9095','2579','1003','1149','11726','2193','1932','2156','1912','10844',
'11727','11052','11053','1010','2163','2293','9465','9461','11057','2167','14501','2294',
'11048','1699','11051','11055','2133','9251','11722','1520','1890','2225','1965','11054','1309',
'6359','1915','1937','2011','11066','2096','9252','1904','10942','9507','2631','5557','9084',
'2098','1256','1328']
dst_dir = "Dynamic_Programming"

for (path, dir, files) in os.walk("./baekjoon"):
    for filename in files:
        ext = os.path.splitext(filename)[-1]
        if filename[:filename.find("_")] in src_num:
            shutil.move(path+"/"+filename, path+"/"+dst_dir+"/"+filename)
