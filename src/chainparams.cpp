// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2015-2017 The AmsterdamCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

// 100 000002efcd0a7b5401f8f964da7d59e7e7bc97683f986d1a295e5a73eca82115
// 1000 000000050f6aef7d6f40d0cdf0e0aa7d1c2e61df8baa749690362ea17d0858cc
// 2500 00000001391861008686ef56ad88dc081008fcbf0d3f8b35feaaa8f9f5b1bf38
// 5000 00000006c99fde6e870ace24f99cebc6f8515df5afb06fe8a086a4f12962e674
// 10000 0000000104ef393983220a2eec841527ff61cd04ad3b98cfbf83f6ebdfd2dd33
// 25000 0000000099d13ab3e0210d072a7ab394c1ec3e8a2efe9c3835fa5c3f36d5623c
// 50000 000000034bdb1897922d0dd2608ccd71ec3782a021ddb619c3366195e3210b4c
// 75000 000000008f1aa425f16d3858160f3f9db4d8df7f471b8b243d493a075de28e53
// 100000 000000001a2a84195221e3f9a0ffecbd80b7f8c308c8144f5781dbcdbb3ce3ce
// 125000 0000000164a51694ebddfc2d653625e77f30344c3f5618f0b79a773b5fa14c04
// 140000 00000000ce15c109cd977c89cac631932b9706ffa3236ae71ccf755281d74163
// 145000 00000000978ef8e749fbb77b6d8be5d8e92f6e78192752adee6d4734888a9e27
// 163813 00000000fbaeeb07c4355c4c2f90548991189e89c2928e6048def02e226ffead

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x00000c393bf1eaf9757be560092cc08a7b1ff0345e874b12521522e27862d7d7"))
	(2, uint256("0x00000310d966793ec3dd080a97b10afa0c848432c01b4053d2c6f206e1449e28"))
	(67260, uint256("0x0000000009e85f5c57095d56743bc79f347d36ebf1e142b17ba47f4f2c587b6e"));
    //(1, uint256(""));
	(20000, uint256("0x0000000000e1a4f0659738de768c662164a20f11ca16c77dde422ee2d7369a80"))
	(30000, uint256("0x00000000040ac4aa7fda2d6fdd2745c788469b482eec8da79842e88bbbfc70c3"))
	(40000, uint256("0x0000000003265c4aded591f0b648b626abf0e4316295b6baeeadbb6c744f768e"))
	(50000, uint256("0x00000000052c4943642d41377f0968650871a5351c896a4cfe74e41edd2adf28"))
	(60000, uint256("0x00000000016a565d7d8b0c96138a9d6873510fece3beffd5295ea517ce4e6b8d"))
	(70000, uint256("0x00000000039673e6ee9944479068800c78f479dfb6b5d23d748d542af073440d"))
	(80000, uint256("0x0000000008dacfe17e44c93490c36c4d365fb6309f614c05bfa9952e9c08765f"))
	(89319, uint256("0x00000000031005c122f47eef1495a44221632fc7cc94b6b5ff68bc7da826c012"))	
	(95771, uint256("0x00000000021cef5896d94a2d87d928d8fdf943a8d260386471e06b03c635acc6"))
    //(616764, uint256("29dd0bd1c59484f290896687b4ffb6a49afa5c498caf61967c69a541f8191557")) //first block to use modifierV2
	(10000, uint256("0x0000000104ef393983220a2eec841527ff61cd04ad3b98cfbf83f6ebdfd2dd33"))
	(67260, uint256("0x0000000009e85f5c57095d56743bc79f347d36ebf1e142b17ba47f4f2c587b6e"))
    //(623933, uint256("c7aafa648a0f1450157dc93bd4d7448913a85b7448f803b4ab970d91fc2a7da7"));
	(100000, uint256("0x000000001a2a84195221e3f9a0ffecbd80b7f8c308c8144f5781dbcdbb3ce3ce"))
	(125000, uint256("0x0000000164a51694ebddfc2d653625e77f30344c3f5618f0b79a773b5fa14c04"))
	(145000, uint256("0x00000000978ef8e749fbb77b6d8be5d8e92f6e78192752adee6d4734888a9e27"))
	(163813, uint256("0x00000000fbaeeb07c4355c4c2f90548991189e89c2928e6048def02e226ffead"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1520885528, // * UNIX timestamp of last checkpoint block
    1506431510, // * UNIX timestamp of last checkpoint block
    100000,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    14400        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x02;
        pchMessageStart[1] = 0x21;
        pchMessageStart[2] = 0x01;
        pchMessageStart[3] = 0xa1;
        vAlertPubKey = ParseHex("045da9271f5d9df405d9e83c7c7e62e9c831cc85c51ffaa6b515c4f9c845dec4bf256460003f26ba9d394a17cb57e6759fe231eca75b801c20bccd19cbe4b7942d");
        nDefaultPort = 50020;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // AmsterdamCoin starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // AmsterdamCoin: 1 minute
        nTargetSpacing = 1 * 60;  // AmsterdamCoin: 1 minute
        nMaturity = 101;
		nMaxMoneyOut = 10000000000 * COIN;
        /** Height or Time Based Activations **/
        nLastPOWBlock = 259200;
        nModifierUpdateBlock = 1;
		
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nZerocoinStartTime = 1524060000; // Wednesday 18 April 2018 14:00:00 UTC
		nZerocoinStartHeight = 259300;
		
		const char* pszTimestamp = "AmsterdamCoin 30-09-2017";
		
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
				
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("045da9271f5d9df405d9e83c7c7e62e9c831cc85c51ffaa6b515c4f9c845dec4bf256460003f26ba9d394a17cb57e6759fe231eca75b801c20bccd19cbe4b7942d") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1506779239;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 500317;
        hashGenesisBlock = genesis.GetHash();
		
        assert(hashGenesisBlock == uint256("0x00000c393bf1eaf9757be560092cc08a7b1ff0345e874b12521522e27862d7d7"));
        assert(genesis.hashMerkleRoot == uint256("0xa84934befc603b6dc91cd53895bf45cd056b4e7a9562067d7608b94e8704815d"));
		
        vSeeds.push_back(CDNSSeedData("amsterdamcoinnode.dyndns.org", "amsterdamcoinnode.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode1.dyndns.org", "amsterdamcoinnode1.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode2.dyndns.org", "amsterdamcoinnode2.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode3.dyndns.org", "amsterdamcoinnode3.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode4.dyndns.org", "amsterdamcoinnode4.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode5.dyndns.org", "amsterdamcoinnode5.dyndns.org"));
		vSeeds.push_back(CDNSSeedData("amsterdamcoinnode6.dyndns.org", "amsterdamcoinnode6.dyndns.org"));
		
		vSeeds.push_back(CDNSSeedData("node1.amsterdamcoincoin.com", "node1.amsterdamcoincoin.com"));
		vSeeds.push_back(CDNSSeedData("node2.amsterdamcoincoin.com", "node2.amsterdamcoincoin.com"));
		vSeeds.push_back(CDNSSeedData("node3.amsterdamcoincoin.com", "node3.amsterdamcoincoin.com"));
		vSeeds.push_back(CDNSSeedData("node4.amsterdamcoincoin.com", "node4.amsterdamcoincoin.com"));
		vSeeds.push_back(CDNSSeedData("node5.amsterdamcoincoin.com", "node5.amsterdamcoincoin.com"));
		vSeeds.push_back(CDNSSeedData("node6.amsterdamcoincoin.com", "node6.amsterdamcoincoin.com"));

		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
        strSporkKey = "045da9271f5d9df405d9e83c7c7e62e9c831cc85c51ffaa6b515c4f9c845dec4bf256460003f26ba9d394a17cb57e6759fe231eca75b801c20bccd19cbe4b7942d";
        
        strObfuscationPoolDummyAddress = "Sg3aLcSeLqbpEsVgoXtDFrpDYDfAsf1qxv";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 2;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // AmsterdamCoin: 1 day
        nTargetSpacing = 1 * 60;  // AmsterdamCoin: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));
        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "amsterdamcoin-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "amsterdamcoin-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet amsterdamcoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet amsterdamcoin script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet amsterdamcoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet amsterdamcoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet amsterdamcoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short 
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // AmsterdamCoin: 1 day
        nTargetSpacing = 1 * 60;        // AmsterdamCoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}