# GPG Setup (Windows)

## Install GPG
- https://www.gnupg.org/

## Kleopatra
- File - New Open PGP Key Pair - Add Passphrase - Details - Export - Copy PGP PUBLIC KEY BLOCK;

## Open Github 
- Settings - SSH and GPG Keys - New GPG key - Paste the PGP PUBLIC KEY BLOCK;

##  Tell Git to interact with gpg4win
From terminal run:
 - git config --global user.signingkey KEY_ID
 - git config --global commit.gpgsign true
 - git config --global gpg.program "C:\Program Files (x86)\GnuPG\bin\gpg.exe"
 
## More
- https://blog.bsk.im/2018/01/18/signing-git-commits-with-gpg-on-windows-feat-sourcetree/