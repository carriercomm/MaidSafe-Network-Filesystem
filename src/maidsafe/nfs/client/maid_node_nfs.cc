/*  Copyright 2013 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#include "maidsafe/nfs/client/maid_node_nfs.h"

#include "maidsafe/common/error.h"
#include "maidsafe/common/log.h"

#include "maidsafe/nfs/vault/account_creation.h"
#include "maidsafe/nfs/vault/pmid_registration.h"

namespace maidsafe {

namespace nfs_client {

MaidNodeNfs::MaidNodeNfs(AsioService& asio_service, routing::Routing& routing,
                         passport::PublicPmid::Name pmid_node_hint)
    : get_timer_(asio_service),
      get_versions_timer_(asio_service),
      get_branch_timer_(asio_service),
      dispatcher_(routing),
      service_([&]()->std::unique_ptr<MaidNodeService> {
        std::unique_ptr<MaidNodeService> service(
            new MaidNodeService(routing, get_timer_, get_versions_timer_, get_branch_timer_));
        return std::move(service);
      }()),
      pmid_node_hint_mutex_(),
      pmid_node_hint_(pmid_node_hint) {}

passport::PublicPmid::Name MaidNodeNfs::pmid_node_hint() const {
  std::lock_guard<std::mutex> lock(pmid_node_hint_mutex_);
  return pmid_node_hint_;
}

void MaidNodeNfs::set_pmid_node_hint(const passport::PublicPmid::Name& pmid_node_hint) {
  std::lock_guard<std::mutex> lock(pmid_node_hint_mutex_);
  pmid_node_hint_ = pmid_node_hint;
}

void MaidNodeNfs::CreateAccount(const nfs_vault::AccountCreation& /*account_creation*/) {
  assert(0);
}

void MaidNodeNfs::RemoveAccount() {
  assert(0);
}

void MaidNodeNfs::RegisterPmid(const nfs_vault::PmidRegistration& /*pmid_registration*/) {
  assert(0);
}

void MaidNodeNfs::UnregisterPmid(const nfs_vault::PmidRegistration& /*pmid_registration*/) {
  assert(0);
}

void MaidNodeNfs::GetPmidHealth(const passport::Pmid& /*pmid*/) {
  assert(0);
}

}  // namespace nfs_client

}  // namespace maidsafe
