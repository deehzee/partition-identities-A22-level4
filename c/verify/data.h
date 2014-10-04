/**************************************************************\

File: data.h
Author: Debajyoti Nandi
Email: nandi@math.rutgers.edu

Description: 
  Contains the data about the graded dimensions of the level 4
  standard modules for A2(2).
  
  XMN[n] = the coefficient of q^n in the second product 
           expansion (F_{\Lambda}(q)) of the graded dimension 
           of the (M,N)-module.
  
  MN = 40, 21 or 02.
  
  X40[n] is the number of partitions of n into
    parts congruent to +/-{2,3,4} modulo 14.
  
  X21[n] is the number of partitions of n into
    parts congruent to +/-{1,4,6} modulo 14.
    
  X02[n] is the number of partitions of n into
    parts congruent to +/-{2,5,6} modulo 14.
    
  X[n] is the number of all partitions of n.
  
Note:
  These numbers are directly computed from the expansion of 
  the corresponding product formula (using Maple package 
  "powseries").
  
  0 <= n <= MAX-1 (MAX=201 defined below).
  
  We checked the equality of the spanning set for n <= 170.

\**************************************************************/

#ifndef DATA_H
#define DATA_H

#define MAX 201 /* one plus the max */

/* Needs at least 32 bit */
const long X40[MAX] = {1, 0, 1, 1, 2, 1, 3, 2, 4, 3, 6, 5, 9, 7, 
12, 11, 17, 15, 23, 21, 31, 29, 41, 39, 55, 52, 71, 70, 93, 91, 
120, 119, 154, 154, 196, 198, 250, 252, 314, 321, 395, 404, 494, 
508, 615, 635, 762, 790, 943, 978, 1159, 1209, 1423, 1485, 1740, 
1821, 2121, 2224, 2577, 2708, 3126, 3286, 3776, 3980, 4554, 4802, 
5477, 5783, 6571, 6945, 7865, 8321, 9397, 9945, 11197, 11865, 
13320, 14118, 15812, 16770, 18735, 19879, 22155, 23520, 26159, 
27774, 30824, 32746, 36268, 38532, 42601, 45273, 49961, 53104, 
58501, 62193, 68407, 72724, 79863, 84922, 93117, 99012, 108418, 
115289, 126066, 134057, 146394, 155676, 169796, 180546, 196682, 
209140, 227565, 241953, 262984, 279596, 303570, 322717, 350025, 
372071, 403164, 428496, 463857, 492964, 533149, 566517, 612163, 
650394, 702190, 745936, 804669, 854678, 921244, 978328, 1053701, 
1118837, 1204125, 1278328, 1374785, 1459264, 1568262, 1664337, 
1787425, 1896597, 2035525, 2159436, 2316120, 2456690, 2633289, 
2792562, 2991505, 3171854, 3395806, 3599839, 3851793, 4082447, 
4365758, 4626262, 4944619, 5238677, 5596211, 5927823, 6329149, 
6702882, 7153082, 7573964, 8078710, 8552370, 9117990, 9650628, 
10284088, 10882725, 11591784, 12264060, 13057354, 13811892, 
14698931, 15545230, 16536585, 17485229, 18592642, 19655289, 
20891688, 22081420, 23461150, 24792263, 26331227, 27819720, 
29535426, 31198920, 33110760, 34968805, 37098243, 39172364, 
41543017, 43857204, 46495191, 49075706, 52009892, 54885951, 
58148084};

const long X21[MAX] = {1, 1, 1, 1, 2, 2, 3, 3, 5, 5, 7, 7, 10, 
11, 14, 15, 20, 21, 27, 29, 37, 40, 49, 53, 66, 71, 86, 93, 113, 
122, 146, 158, 188, 204, 240, 260, 306, 332, 386, 419, 487, 528, 
609, 661, 760, 825, 943, 1023, 1168, 1267, 1438, 1560, 1767, 
1916, 2162, 2344, 2639, 2860, 3209, 3476, 3894, 4217, 4708, 
5097, 5682, 6148, 6836, 7394, 8207, 8874, 9828, 10621, 11746, 
12689, 14003, 15121, 16665, 17986, 19788, 21348, 23455, 25293, 
27745, 29905, 32766, 35302, 38621, 41592, 45453, 48926, 53399, 
57455, 62639, 67368, 73360, 78862, 85794, 92189, 100180, 107602, 
116823, 125422, 136034, 145987, 158200, 169704, 183731, 197007, 
213120, 228427, 246893, 264519, 285686, 305955, 330174, 353460, 
381161, 407883, 439521, 470148, 506274, 541345, 582526, 622644, 
669581, 715421, 768846, 821178, 881958, 941644, 1010713, 
1078717, 1157172, 1234590, 1323598, 1411652, 1512596, 1612653, 
1727012, 1840620, 1970107, 2098992, 2245472, 2391561, 2557186, 
2722651, 2909739, 3097001, 3308240, 3520000, 3758301, 3997592, 
4266275, 4536476, 4839180, 5144052, 5484912, 5828670, 6212188, 
6599520, 7030829, 7466949, 7951648, 8442383, 8986794, 9538617, 
10149685, 10769785, 11455329, 12151724, 12920294, 13701879, 
14563118, 15439763, 16404234, 17386918, 18466449, 19567341, 
20774941, 22007525, 23357735, 24736987, 26245747, 27788242, 
29473390, 31197471, 33078570, 35004574, 37103408, 39253822, 
41594347, 43994022, 46602870, 49279318, 52185710, 55169310, 
58405745, 61730037, 65332175, 69034230, 73041596};

const long X02[MAX] = {1, 0, 1, 0, 1, 1, 2, 1, 3, 2, 4, 3, 6, 4, 
8, 6, 11, 9, 15, 12, 20, 17, 26, 23, 35, 31, 45, 41, 58, 54, 75, 
70, 96, 91, 121, 117, 154, 149, 193, 189, 242, 239, 302, 299, 
375, 375, 463, 466, 572, 577, 702, 712, 859, 876, 1049, 1072, 
1277, 1310, 1548, 1594, 1875, 1934, 2262, 2340, 2723, 2825, 
3271, 3398, 3920, 4081, 4685, 4887, 5592, 5839, 6656, 6962, 
7908, 8284, 9379, 9833, 11103, 11654, 13116, 13782, 15473, 
16270, 18218, 19173, 21416, 22557, 25137, 26489, 29458, 31063, 
34466, 36366, 40275, 42510, 46989, 49620, 54749, 57839, 63706, 
67319, 74032, 78257, 85916, 90846, 99594, 105327, 115302, 
121966, 133332, 141065, 154005, 162955, 177684, 188036, 
204771, 216726, 235748, 249522, 271114, 286975, 311469, 329709, 
357475, 378409, 409874, 433884, 469493, 496997, 537294, 568750, 
614307, 650257, 701730, 742769, 800888, 847671, 913268, 966560, 
1040520, 1101165, 1184537, 1253465, 1347369, 1425654, 1531362, 
1620192, 1739117, 1839800, 1973535, 2087573, 2237838, 2366892, 
2535676, 2681578, 2871034, 3035871, 3248420, 3434499, 3672822, 
3882693, 4149796, 4386347, 4685500, 4951920, 5286847, 5586662, 
5961417, 6298600, 6717710, 7096653, 7565130, 7990684, 8514112, 
8991718, 9576197, 10111869, 10764269, 11364646, 12092472, 
12764978, 13576575, 14329409, 15233989, 16076195, 17083983, 
18025646, 19147834, 20200078, 21449166, 22624261, 24013932, 
25325521, 26870925, 28334046, 30051881, 31683105, 33591834};

/* Needs at least 64 bit */
const long long X[MAX] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 
56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792, 1002, 1255, 
1575, 1958, 2436, 3010, 3718, 4565, 5604, 6842, 8349, 10143, 
12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583, 53174, 
63261, 75175, 89134, 105558, 124754, 147273, 173525, 204226, 
239943, 281589, 329931, 386155, 451276, 526823, 614154, 715220, 
831820, 966467, 1121505, 1300156, 1505499, 1741630, 2012558, 
2323520, 2679689, 3087735, 3554345, 4087968, 4697205, 5392783, 
6185689, 7089500, 8118264, 9289091, 10619863, 12132164, 13848650, 
15796476, 18004327, 20506255, 23338469, 26543660, 30167357, 
34262962, 38887673, 44108109, 49995925, 56634173, 64112359, 
72533807, 82010177, 92669720, 104651419, 118114304, 133230930, 
150198136, 169229875, 190569292, 214481126, 241265379, 271248950, 
304801365, 342325709, 384276336, 431149389, 483502844, 541946240, 
607163746, 679903203, 761002156, 851376628, 952050665, 
1064144451, 1188908248, 1327710076, 1482074143, 1653668665, 
1844349560, 2056148051, 2291320912, 2552338241, 2841940500, 
3163127352, 3519222692, 3913864295, 4351078600, 4835271870, 
5371315400, 5964539504, 6620830889, 7346629512, 8149040695, 
9035836076, 10015581680, 11097645016, 12292341831, 13610949895, 
15065878135, 16670689208, 18440293320, 20390982757, 22540654445,
24908858009, 27517052599, 30388671978, 33549419497, 37027355200,
40853235313, 45060624582, 49686288421, 54770336324, 60356673280,
66493182097, 73232243759, 80630964769, 88751778802, 97662728555,
107438159466, 118159068427, 129913904637, 142798995930, 
156919475295, 172389800255, 189334822579, 207890420102, 
228204732751, 250438925115, 274768617130, 301384802048, 
330495499613, 362326859895, 397125074750, 435157697830, 
476715857290, 522115831195, 571701605655, 625846753120, 
684957390936, 749474411781, 819876908323, 896684817527, 
980462880430, 1071823774337, 1171432692373, 1280011042268, 
1398341745571, 1527273599625, 1667727404093, 1820701100652, 
1987276856363, 2168627105469, 2366022741845, 2580840212973, 
2814570987591, 3068829878530, 3345365983698, 3646072432125, 
3972999029388};

#endif