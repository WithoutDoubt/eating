
from sphfile import SPHFile
import glob
import os

noise_PATH = " D:/0dataset/data/lisa/data/timit/raw/TIMIT/TEST"

rootdir = noise_PATH
for roots,dirs,files in os.walk(rootdir): 
    for file_1 in files: 
        path_x = os.path.join(roots,file_1)
        if path_x[-4:] == '.WAV':

            with open(txt_file,'a') as f:
                f.write("\n"+os.path.join(roots,file_1))



 
if __name__ == "__main__":
    path = 'C:/Users/Administrator/Desktop/Experiment_python/datasets/timit/fcjf0/*.wav'
    path = 'D:/dataset/data/lisa/data/timit/raw/TIMIT/TEST/DR1/FAKS0/*.WAV'
    sph_files = glob.glob(path)
    print(len(sph_files),"train utterences")
    for i in sph_files:
        sph = SPHFile(i)
        sph.write_wav(filename=i.replace(".wav","_n.wav"))
        # os.remove(i)    # 不用删除语音文件
    print("Completed")