# calcDensityCoin
免責聲明：
0- calcDensity這個soft，只用於計算圓形銀幣密度。雖然正確率很高，但仍有可能因爲深打以及誤差原因造成密度數值偏差，在此，不承擔任何因爲計算誤差所引起的任何責任。

使用説明：
1- 你需要有一個C++語言的編譯器。
  1.1- 如果使用Windows，你可以下載DevC++ 5.11這個玩具IDE
  1.2- 如果是Mac，那就已經損失了我為非developer做這個所見即所得的簡單soft的初衷了 （你當然可以運行g++來編譯）
2- 你可以把你的任意coin信息填在densityCalc.in中（如同給的三個樣例）
3- 在DevC++中，按下F11運行
  3.1 如果結果接近10，或最少超過9.2，那麽基本上是銀幣
  3.2 如果結果不到9，那麽基本上是銅幣，或者是銅芯包銀
  3.3 有個別銀幣因爲形制關係，會看起來密度數值較低（美國銀鷹）
4- 如果你想要有一個非常准確的測試，請使用金屬成分分析儀（而不是calcDensity）
