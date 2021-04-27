#pragma once

#include "storage/background_downloading/downloader_queue_ios.hpp"
#include "storage/map_files_downloader_with_ping.hpp"

namespace storage
{
class BackgroundDownloaderAdapter : public MapFilesDownloaderWithPing
{
public:
  // MapFilesDownloader overrides:
  void Remove(CountryId const & countryId) override;

  void Clear() override;

  QueueInterface const & GetQueue() const override;

private:
  // MapFilesDownloaderWithServerList overrides:
  void Download(QueuedCountry && queuedCountry) override;

  // Trying to download mwm from different servers recursively.
  void DownloadFromAnyUrl(CountryId const & countryId, std::string const & downloadPath,
                          std::vector<std::string> const & urls);

  BackgroundDownloaderQueue m_queue;
};
}  // namespace storage
