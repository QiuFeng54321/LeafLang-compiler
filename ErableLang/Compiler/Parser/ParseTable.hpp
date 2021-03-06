//
// Created by Qiufeng54321 on 2019-07-02.
// Copyright (c) Qiufeng54321 All rights reserved.
//

#ifndef ERABLELANG_PARSETABLE_HPP
#define ERABLELANG_PARSETABLE_HPP

#include <ostream>
#include <unordered_map>
#include "Headers.hpp"

namespace Erable::Compiler::Parser {
	inline std::unordered_set<IterationNode *> INDuplicateBuffer;

	enum class ActionType {
		STATE,
		REDUCE,
		ACCEPT
	};

	struct Action {
		ActionType type;
		int i;

		bool operator==(const Action &rhs) const;

		friend std::ostream &operator<<(std::ostream &os, const Action &action);

	};

	struct IterationNode {
		int iterationIndex;
		Symbols::SymbolList symbols;

		IterationNode(int iterationIndex, const Symbols::SymbolList &symbols);

		std::string toString();
	};

	class RuleIteration {
	public:
		int currentIndex = -1;
		IterationNode *rootNode;

		/**
		 * Calls shiftDot on every symbol in the node
		 */
		void shiftDot(IterationNode *);

		/**
		 * Find the symbol which is equal to the other.
		 * @return Symbol found or $EOT
		 */
		Symbols::SymbolPtr find(Symbols::SymbolPtr);

		/**
		 * Find the symbol which is totally equal to the other.
		 * @return Symbol found or $EOT
		 */
		IterationNode *findMatch(Symbols::SymbolPtr);

		/**
		 * Entry function for generating the whole iteration.
		 * Will first call generateFirstRound and then calls _generate
		 */
		void generate();

		/**
		 * Only generate one round
		 */
		void generateOneRound(IterationNode *);

		/**
		 * Generate the first round for the Iteration(I0).
		 */
		void generateFirstRound();

		static void recursiveExpandRule(IterationNode *node, Symbols::SymbolPtr &symbol);

		/**
		 * If the symbol followed by the dot is a rule, expand the rule and keep doing this.
		 * @param node
		 * @param symbol
		 */
		static void
		recursiveExpandRule(Symbols::SymbolList &duplicateBuffer, IterationNode *node, Symbols::SymbolPtr &symbol);

		bool isFinished(IterationNode *node);

		static bool notDuplicate(Symbols::SymbolSet &duplicateBuffer, Symbols::SymbolPtr sym);

		static bool notDuplicate(Symbols::SymbolList &duplicateBuffer, Symbols::SymbolPtr sym);

		static bool isExactlyDuplicate(Symbols::SymbolList &duplicateBuffer, Symbols::SymbolPtr sym);

		static bool exactlyDuplicateWithLookahead(Symbols::SymbolList &duplicateBuffer, Symbols::SymbolPtr sym);

	protected:
		Symbols::SymbolPtr _find(IterationNode *node, Symbols::SymbolPtr symbolPtr, bool matchDotAndLookahead);

		IterationNode *_find(std::unordered_set<IterationNode *> &searched, IterationNode *node,
							 Symbols::SymbolPtr symbolPtr);

		void _generate(std::unordered_set<IterationNode *> &duplicateBuffer, IterationNode *);


	};

	class ParseTable {
	public:
		typedef std::unordered_multimap<std::string, Action> ActionLine;
		typedef std::vector<ActionLine> ActionTable;
		RuleIteration iteration;
		ActionTable parseTable;
		int stateAmount;
		int maxWidth = 10;
		ParseTable(const RuleIteration &iteration, int stateAmount);

		ParseTable(const RuleIteration &iteration);

		ParseTable(int stateAmount);

		int getStateAmount() const;

		void setStateAmount(int amount);

		void generateTable();

		friend std::ostream &operator<<(std::ostream &os, const ParseTable &table);

		const ActionTable &getParseTable() const;

		void setParseTable(const ActionTable &parseTable);

	protected:
		void _generateTable(IterationNodeSet &duplicateBuffer);

		void _generateTable(IterationNodeSet &duplicateBuffer, IterationNode *node);

		void _place(int line, std::string key, Action action);

		void _place(int line, std::vector<std::string> keys, Action action);

		void _place(int line, Symbols::SymbolList symbols, Action action);

		void _place(int line, Symbols::SymbolSet symbols, Action action);
	};
}

std::ostream &operator<<(std::ostream &os, Erable::Compiler::Parser::IterationNode *node);

#endif //ERABLELANG_PARSETABLE_HPP
