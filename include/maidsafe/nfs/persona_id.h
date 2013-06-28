/* Copyright 2012 MaidSafe.net limited

This MaidSafe Software is licensed under the MaidSafe.net Commercial License, version 1.0 or later,
and The General Public License (GPL), version 3. By contributing code to this project You agree to
the terms laid out in the MaidSafe Contributor Agreement, version 1.0, found in the root directory
of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also available at:

http://www.novinet.com/license

Unless required by applicable law or agreed to in writing, software distributed under the License is
distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing permissions and limitations under the
License.
*/

#ifndef MAIDSAFE_NFS_PERSONA_ID_H_
#define MAIDSAFE_NFS_PERSONA_ID_H_

#include "maidsafe/common/node_id.h"

#include "maidsafe/nfs/types.h"


namespace maidsafe {

namespace nfs {

struct PersonaId {
  PersonaId();
  PersonaId(Persona persona_in, const NodeId& node_id_in);
  PersonaId(const PersonaId& other);
  PersonaId& operator=(const PersonaId& other);
  PersonaId(PersonaId&& other);
  PersonaId& operator=(PersonaId&& other);

  Persona persona;
  NodeId node_id;
};

}  // namespace nfs

}  // namespace maidsafe

#endif  // MAIDSAFE_NFS_PERSONA_ID_H_