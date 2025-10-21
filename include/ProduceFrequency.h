#ifndef PRODUCEFREQUENCY_H
#define PRODUCEFREQUENCY_H

#include <string>
#include <map>

class ProduceFrequency {
private:
  std::map<std::string, int> m_itemFrequency;
  std::string m_inputFileName;
  std::string m_backupFileName;

public:
  ProduceFrequency();

  void LoadDataFromFile();
  int GetItemFrequency(const std::string & item) const;
  void PrintAllFrequencies() const;
  void PrintHistogram() const;
  void WriteBackupFile() const;
  void RunMenu();
};

#endif // PRODUCEFREQUENCY_H
